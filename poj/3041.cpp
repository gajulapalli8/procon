#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 1919; // TODO:initialize
const int F_INF = 114514; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,G[to].size()});
    G[to].pb({from,0,G[from].size()-1});
}

void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(e.cap>0 && level[e.to]<0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスをdfsで探す
int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=iter[v]; i<G[v].size(); i++){
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            int d = dinic_dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        dinic_bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while( (f=dinic_dfs(s,t,F_INF)) > 0 ) flow+=f;
    }
}

int main()
{
    int N,K;
    scanf(" %d %d", &N, &K);

    int S=0, T=2*N+1;
    rep(i,N) add_edge(S,i+1,1);
    rep(i,N) add_edge(N+1+i,T,1);

    rep(i,K)
    {
        int R,C;
        scanf(" %d %d", &R, &C);
        add_edge(R,N+C,1);
    }

    printf("%d\n", max_flow(S,T));
    return 0;
}
