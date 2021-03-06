#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct RollingHash{
    static const int MD = 3;
    const vector<ll> hash_base{1009,1021,1013};
    const vector<ll> hash_mod{1000000009,1000000007,1000000021};

    int n;
    vector<ll> hs[MD], pw[MD];

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        for(int i=0; i<MD; ++i){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for(int j=0; j<n; ++j){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }

    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }

    // 1-index
    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        for(int i=0; i<MD; ++i) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }

    vector<ll> calc(int l, int r){
        vector<ll> ret;
        rep(i,3) ret.pb(hash_value(l-1,r,i));
        return ret;
    }
};

int main()
{
    int n,m;
    string s;
    cin >>n >>m >>s;

    RollingHash RH(s);
    set<vector<ll>> X;
    int L=1,R=1;
    while(m--)
    {
        string q;
        cin >>q;

        int add=1;
        if(q[1]=='-') add=-1;

        if(q[0]=='R') R+=add;
        else L+=add;

        X.insert(RH.calc(L,R));
    }

    cout << X.size() << endl;
    return 0;
}
