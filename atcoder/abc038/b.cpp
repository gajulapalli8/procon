#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main()
{
    int h1,h2,w1,w2;
    cin >>h1 >>w1 >>h2 >>w2;

    string ans="NO";
    if(h1==h2 || h1==w2 || w1==h2 || w1==w2) ans="YES";
    cout << ans << endl;

    return 0;
}
