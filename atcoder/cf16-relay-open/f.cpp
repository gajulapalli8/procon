#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int f(ll n)
{
    if(n<3) return 0;
    return 1+f((n-1)/2);
}

int main()
{
    int x;
    cin >>x;

    ll l=0, r=1LL<<44;
    while(r-l>1)
    {
        ll m = (l+r)/2;
        if(f(m)<=x) l=m;
        else r=m;
    }
    cout << l << endl;
    return 0;
}
