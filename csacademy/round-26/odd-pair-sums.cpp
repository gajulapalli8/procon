#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int ans=0;
    int idx=0;
    for(int i=1; i<n; ++i)
    {
        if((a[idx]+a[i])%2==0) ++ans;
        else idx=i;
    }

    cout << ans << endl;
    return 0;
}
