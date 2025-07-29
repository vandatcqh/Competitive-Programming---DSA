#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
int n, k;
long double A[N];
bool Check(long double x)
{
    long double sum = 0;
    for(int i = 1; i <= n; i++)
    if(A[i] >= x) sum += A[i] - x;
    else sum -= (x - A[i])*100/(100-k);
    return sum >= 0;
}
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> A[i];
    long double l = 0, r = 1000, res = 0;
    for(int div = 1; div <= 35; div++)
    {
        long double mid = (l + r)/2;
        if(Check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(7) << l;
}

