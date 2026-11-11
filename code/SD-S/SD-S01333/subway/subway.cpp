#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
void readd(T& x){
	x=0;
	int f=1;
	char c=getchar();
	while(c!='-'&&(c>'9'||c<'0')) c=getchar();
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	x*=f;
}
/*
template<typename T>
void printt(T x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) printt(x/10);
	putchar(x%10+'0');
}*/
const ll M=10086;
const ll maxn=0x3f3f3f3f3f3f;
int w[M];
int way[510][M];//i,j->第i条线j的耗时 
vector<int> sub[M];//i,j->第i站的有的线路 
ll dp[M][M];
void dfs(int l,int r){
	if(dp[l][r]!=maxn) return ;
	for(int i=l+1;i<r;i++){
		dfs(l,i);
		dfs(i,r);
		dp[l][r]=min(dp[l][r],dp[l][i]+dp[i][r]);
	}
	for(auto& xian:sub[l]){
		for(auto& zhan:way[xian]){
			dp[l][zhan]
		}
	}
	//while(1);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	/*
	c表示测试点编号、n地铁线路数500、m地铁站数5e5、d每个地铁站最多被几条线路经过20，q以及出行计划数1e5
	*/
	readd(c);
	readd(n);
	readd(m);
	readd(d);
	readd(q);
	for(int i=1;i<=m;i++) readd(w[i]);
	ll k,xxx,yyy;
	for(int i=1;i<=n;i++){
		readd(k);
		for(int j=1;j<=k;j++){
			readd(xxx);//经xxx站 
			readd(yyy);//好事yyy 
			sub[xxx].push_back(i);
			way[i][xxx]=yyy;
		}
	}
	for(int i=0;i<n+3;i++){
		fill(dp[i],dp[i]+n+3,maxn);
	}/*
	for(int i=0;i<n+4;i++){
		for(int j=0;j<n+4;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	while(q--){
		readd(xxx);
		readd(yyy);
		dfs(xxx,yyy);
		cout<<dp[xxx][yyy]<<'\n';
	}
	return 0;
}

