#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {int a;cin>>a;
        arr[i].first=a;
        arr[i].second = i + 1;
    }

    vector<int> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i].first + arr[j].first + arr[k].first;
            if (sum < x) {
                j++;
            } else if (sum > x) {
                k--;
            } else {
                ans.push_back(arr[i].second);
                ans.push_back(arr[j].second);
                ans.push_back(arr[k].second);
                break;
            }
        }
        if (!ans.empty()) break;
    }

    if (ans.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
