#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    ll x,y,a,b;
    cin >>x >>y >>a >>b;

    double k = (double)(a*x+b*y)/(a*a+b*b);
    double n = (double)(a*y-b*x)/(a*a+b*b);

    printf("%.10lf\n%.10lf\n",k,n);
    return 0;
}
