struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobScheduling(Job arr[], int n) {
    sort(arr, arr + n, cmp);

    int maxD = 0;
    for (int i = 0; i < n; i++)
        maxD = max(maxD, arr[i].deadline);

    vector<int> slot(maxD + 1, -1);

    int count = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = arr[i].id;
                count++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    return {count, totalProfit};
}