#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> x(n);
    int xo = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        xo = xo ^ arr[i];
        x[i] = xo;
    }

    vector<pair<int, int>> query(q);

    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first >> query[i].second;
    }

    for (int i = 0; i < q; i++)
    {
        int a1 = query[i].first;
        int a2 = query[i].second;

        a1--;
        a2--;

        int xorr;
        if (a1 == 0)
        {
            xorr = x[a2];
        }
        else
        {
            xorr = x[a2] ^ x[a1 - 1];
        }

        cout << xorr << endl;
    }

    return 0;
}
