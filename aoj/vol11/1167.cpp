#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	//正四面体数とその中から奇数のものだけを抜きとったものを用意
	int sq[200]={0};
	int oddsq[200]={0};
	//その配列のindexを保存
	int index=0;
	int indexODD=0;
	 //dp初期化用の値
	int INF=2000000;
	
	for(int i=0; (i+1)*(i+2)*(i+3)/6<=1000000; ++i){
		sq[i]=(i+1)*(i+2)*(i+3)/6;
		if(sq[i]%2==1) oddsq[indexODD++]=sq[i];	
		//printf("%3d :%7d\n",i, sq[i]);
		index=i+1;
	}
	//printf("index= %d, inODD = %d\n", index, indexODD);
	
	//dpA[i]:=数iを正四面体数の和として表すときに必要な正四面体数の数の最小値		
	int dpA[1000001];
	fill(dpA,dpA+1000001,INF);
	dpA[0]=0;
		
	for(int i=0; i<1000001; ++i){
		for(int j=0; j<index; ++j){
			if(i+sq[j]<1000001) dpA[i+sq[j]]=min(dpA[i+sq[j]],dpA[i]+1);
			else break;	
		}	
	}
		
	//dpB[i]:=数iを正四面体数の和として表すときに必要な「奇数の」正四面体数の数の最小値		
	int dpB[1000001];
	fill(dpB,dpB+1000001,INF);
	dpB[0]=0;
		
	for(int i=0; i<1000001; ++i){
		for(int j=0; j<indexODD; ++j){
			if(i+oddsq[j]<1000001) dpB[i+oddsq[j]]=min(dpB[i+oddsq[j]],dpB[i]+1);
			else break;	
		}	
	}
		
	while(1){
		int n;
		scanf(" %d", &n);
		if(n==0) break;
		printf("%d %d\n", dpA[n], dpB[n]);
	}	
}