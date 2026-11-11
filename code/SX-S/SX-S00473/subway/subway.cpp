#include<bits/stdc++.h>
using namespace std;
const long long M=1000,N=1000005;
long long t1[N],ps[N],pe[N],t2[N];//站听
long long dp[M][M],xl[M][M];
long long n,m;
int c,k,tt,d,r,zd;
long long aaa(int a,int b){
	long long ans=0,mmm=100000000000000000;
	for(in i=1;i<=m;i++){

		if(a==b)break;
		if(xl[s][i]!=-1){

			s++;

			aaa(s,b);
			ans+=xl[s][i];

  		}

	}
	mmm=min(ans,mmm);
	returm mmm;
}

void answer(int s){
	for(int i=1;i<=r;i++){
		for(int i=1;i<=d;i++){
			if(xl[s][i]!=-1){

			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>r;
	for(int i=1,i<=m;i++){
		cin>>t1[1];
	}
	for(int i=1;i<=n;i++){
		cin>>k;

		for(int j=1,j<=k;j++){
	    	cin>>zd>>tt
			xl[zd][i]=-1;
			xl[zd][i]=tt;
		}
	}
	for(int i=1;i<=r){
		cin>>ps[i]>>pe[i];
	}
	for(int i=1;i<=m;i++){
	    answer(i);
	}


	return 0;
}

