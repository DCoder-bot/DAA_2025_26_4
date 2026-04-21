#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const double TIMEOUT_MS = 2000.0;

struct Metrics {
    string algorithmName;
    int inputSize = 0;
    double executionTime = 0.0; // in microseconds
    long long operations = 0;
    string status = "Completed";
};

// 1. Binary Search
int binarySearch(const vector<int>& arr, int target, Metrics& metrics) {
    auto start = high_resolution_clock::now();

    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        metrics.operations++;

        if (arr[mid] == target) {
            auto end = high_resolution_clock::now();
            metrics.executionTime = duration<double, micro>(end - start).count();
            return mid;
        }
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    auto end = high_resolution_clock::now();
    metrics.executionTime = duration<double, micro>(end - start).count();
    return -1;
}

// 2A. Subset Sum Verification
bool verifySubsetSum(const vector<int>& subset, int target, Metrics& metrics) {
    auto start = high_resolution_clock::now();

    int sum = 0;
    for (int x : subset) {
        metrics.operations++;
        sum += x;
    }

    auto end = high_resolution_clock::now();
    metrics.executionTime = duration<double, micro>(end - start).count();

    return sum == target;
}

// 2B. Subset Sum Decision
bool subsetRec(const vector<int>& arr, int n, int target,
               Metrics& metrics, time_point<high_resolution_clock> start) {

    metrics.operations++;

    if (duration<double, milli>(high_resolution_clock::now() - start).count() > TIMEOUT_MS) {
        metrics.status = "Timeout";
        return false;
    }

    if (target == 0) return true;
    if (n == 0) return false;

    return subsetRec(arr, n - 1, target, metrics, start) ||
           subsetRec(arr, n - 1, target - arr[n - 1], metrics, start);
}

bool solveSubsetSum(const vector<int>& arr, int target, Metrics& metrics) {
    auto start = high_resolution_clock::now();

    bool result = subsetRec(arr, arr.size(), target, metrics, start);

    metrics.executionTime = duration<double, micro>(
        high_resolution_clock::now() - start).count();

    return result;
}

// 3. TSP Brute Force
int tsp(const vector<vector<int>>& graph, Metrics& metrics) {
    auto start = high_resolution_clock::now();

    int n = graph.size();
    vector<int> v;

    for (int i = 1; i < n; i++) v.push_back(i);

    int minCost = INT_MAX;

    do {
        metrics.operations++;

        if (duration<double, milli>(high_resolution_clock::now() - start).count() > TIMEOUT_MS) {
            metrics.status = "Timeout";
            break;
        }

        int cost = 0, k = 0;

        for (int i : v) {
            cost += graph[k][i];
            k = i;
        }
        cost += graph[k][0];

        minCost = min(minCost, cost);

    } while (next_permutation(v.begin(), v.end()));

    metrics.executionTime = duration<double, micro>(
        high_resolution_clock::now() - start).count();

    return minCost;
}

// Print
void print(const Metrics& m) {
    cout << left << setw(25) << m.algorithmName
         << setw(12) << m.inputSize
         << setw(12) << m.status
         << setw(15) << m.operations
         << fixed << setprecision(2)
         << m.executionTime << " microseconds\n";
}

int main() {
    cout << string(90, '-') << "\n";
    cout << setw(25) << "Algorithm"
         << setw(12) << "Input Size"
         << setw(12) << "Status"
         << setw(15) << "Operations"
         << "Time\n";
    cout << string(90, '-') << "\n";

    // Binary Search
    vector<int> arr(1000000);
    iota(arr.begin(), arr.end(), 1);

    Metrics m1;
    m1.algorithmName = "Binary Search";
    m1.inputSize = arr.size();

    // repeat to get measurable time
    for(int i = 0; i < 10000; i++)
        binarySearch(arr, 999999, m1);

    print(m1);

    // Subset Verification
    Metrics m2;
    m2.algorithmName = "Subset Verify";
    vector<int> subset = {10, 20, 30, 40, 50, 60};
    m2.inputSize = subset.size();

    verifySubsetSum(subset, 210, m2);
    print(m2);

    // Subset Decision
    Metrics m3;
    m3.algorithmName = "Subset Decision";
    vector<int> subset2 = {3, 34, 4, 12, 5, 2, 10, 15};
    m3.inputSize = subset2.size();

    solveSubsetSum(subset2, 30, m3);
    print(m3);

    // TSP
    vector<vector<int>> g = {
        {0,10,15,20,25},
        {10,0,35,25,17},
        {15,35,0,30,28},
        {20,25,30,0,23},
        {25,17,28,23,0}
    };

    Metrics m4;
    m4.algorithmName = "TSP (Brute)";
    m4.inputSize = g.size();

    tsp(g, m4);
    print(m4);

    cout << string(90, '-') << "\n";
}