#include <bits/stdc++.h>
#define task ""


using namespace std;
const int N = 3e5 + 5;
const int max_mask = (1 << 8) + 5;
int n, m;
int A[N][9], C[max_mask];
vector < int > Check(int x)
{
    for(int i = 0; i < (1 << m); i++) C[i] = 0;

    for(int i = 1; i <= n; i++)
    {
        int u = 0;
        for(int j = 1; j <= m; j++)
            if(A[i][j] >= x) u |= 1 << (j - 1);
        C[u] = i;
    }
    vector < int > res;
    for(int i = 0; i < (1 << m); i++)
        for(int j = 0; j < (1 << m); j++)
        if(C[i] && C[j] && (i | j) == (1 << m) - 1)
        {
            res.push_back(1);
            res.push_back(C[i]);
            res.push_back(C[j]);
            return res;
        }
    return {0};
}
int main()
{
    if(fopen(task ".inp","r"))
    {
        freopen(task ".inp","r",stdin);
        freopen(task ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> A[i][j];

    int l = 0, r = 1e9, mid;
    vector < int > tmp, res;
    while(l <= r)
    {
        mid = (l + r)/2;
        tmp = Check(mid);
        if(tmp[0])
        {
            res = tmp;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res[1] << " " << res[2];
}
