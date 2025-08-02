#include <bits/stdc++.h>
#define task "main"

using namespace std;
const int N = 1e4 + 5;
int n;
long long A[N], B[N], c;
long long l, r, mid, res_high, res_low;
bool CheckHigh(long long x)
{
    long long sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(1.*A[i]*x/B[i] > c) return 0;
        sum += 1 + A[i]*x/B[i];
        if(sum > c) return 0;
    }
    return 1;
}
bool CheckLow(long long x)
{
    long long sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(1.*A[i]*x/B[i] >= c) return 1;
        sum += 1 + A[i]*x/B[i];
        if(sum >= c) return 1;
    }
    return 0;
}
int main()
{

    if(fopen(task ".inp","r"))
    {
        freopen(task ".inp","r",stdin);
        freopen(task ".out","w",stdout);
    }
    cin >> n >> c;
    bool zero = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> A[i] >> B[i];
        if(A[i] != 0) zero = 0;
    }
    if(zero)
    {
        if(c == n) cout << -1;
        else cout << 0;
        return 0;
    }
    l = 1; r = 1e18; res_high = 0;
    //Tìm res_high lớn nhất mà sum(1 + a * res_high/b) <= c
    while(l <= r)
    {
        mid = (l + r)/2;
        if(CheckHigh(mid))
        {
            res_high = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    l = 1; r = 1e18; res_low = 0;
    //Tìm res_low nhỏ nhất mà sum(1 + a * res_high/b) >= c
    while(l <= r)
    {
        mid = (l + r)/2;
        if(CheckLow(mid))
        {
            res_low = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << max(res_high - res_low + 1, 0LL);
}

