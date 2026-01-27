#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
using namespace std;
using namespace std::chrono;

int operations = 0;


void complexRec(int n) {


   if (n <= 2) {
       operations++;
       return;
   }
   //Constant O(1) work

   int p = n;

   operations++;
   while (p > 0) {
       operations++;
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           operations++;
           temp[i] = i ^ p;
           operations++;
       }
       p >>= 1;
       operations++;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       operations++;
       small[i] = i * i;
       operations++;
   }

   operations++;
   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       operations++;
   } else {
       reverse(small.begin(), small.end());
       operations++;
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}


int main() {
   int n = 1 << 10; 
   auto start = high_resolution_clock::now();
   complexRec(n);
   auto end = high_resolution_clock::now();
   auto duration = duration_cast<milliseconds>(end - start);
   cout << "Total operations: " << operations << endl;
   cout << "Execution time: " << duration.count() << " ms" <<endl;
   return 0;
}

/*
3T(n/2)+nlogn+2n+1
3T(n/2)+nlogn
a = 3
b= 2
f(n) = nlogn = n^klog^pn
k = 1
p = 1
by comparison
1.6 > 1
case 1 of master theorem will be used 
o(n^log base 2 of 3)
*/