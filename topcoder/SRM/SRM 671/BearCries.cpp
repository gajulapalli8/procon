#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

const long mod=1e9+7;

class BearCries {
    public:
    string s;
    long dp[201][70][70];

    long rec(int now, int a, int b){
      if(dp[now][a][b]>=0) return dp[now][a][b];

      if(now==s.size()) return (a==0)&&(b==0);

      long ret=0;
      if(s[now]==';'){
        //区間を開く
        if(a<69){
          ret+=rec(now+1,a+1,b);
          ret%=mod;
        }
        //区間を閉じる
        if(b>0 && b<69){
          ret+=b*rec(now+1,a,b-1);
          ret%=mod;
        }
      }
      else{
        //まだ1つもアンダーバーを持っていないのに割り当てる
        if(a>0 && b<69){
          ret+=a*rec(now+1,a-1,b+1);
          ret%=mod;
        }
        //すでに1つ以上持っているのに割り当てる
        if(b>0 && b<69){
          ret+=b*rec(now+1,a,b);
          ret%=mod;
        }
      }

      return dp[now][a][b]=ret%mod;
    }

    int count(string message) {
      s=message;
      memset(dp,-1,sizeof(dp));
      long ret=rec(0,0,0);
      return (int)ret;
    }
};

// CUT begin
ifstream data("BearCries.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string message, int __expected) {
    time_t startClock = clock();
    BearCries *instance = new BearCries();
    int __result = instance->count(message);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string message;
        from_stream(message);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(message, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456657591;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "BearCries (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
