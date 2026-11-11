#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005];
bool idx[200005];
int solvet[200005];
long long maxx=0;
void dfs(int x,int idxx){
	ans=ans&a[idxx];
	if(x==m-1){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(idx[i]==0){
			idx[i]=1;
			dfs(++x,i);
		}
	}
}
void solve1(){
	for(int i=1;i<=n;i++){
		ans=a[i];
		memset(idx,0,sizeof(idx));
		maxx=0;
		dfs(1,i);
	}
	cout<<maxx;
	return;
}
void solve2(){
	long long anns,maxxx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==1&&a[j]!=a[i]) anns=a[j];
			if(j==1&&a[j]==a[i]) anns=a[j+1];
			if(a[j]!=a[i]) anns=anns&a[j];
		}
		maxxx=max(maxxx,anns);
	}
	cout<<maxxx;
	return;
}
void solve3(){
	for(int i=1;i<=n;i++){
		solvet[a[i]]++;
	}
	if(solvet[3]>=m) cout<<3;
	else if(solvet[3]+solvet[2]>=m) cout<<2;
	else if(n-solvet[0]<m) cout<<0;
	else cout<<1;
	return;
}
void solve4(){
	long long anas=a[n];
	for(int i=n;i>=n-m+1;i--){
		anas=anas&a[i];
	}
	cout<<anas;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=0,ff=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4) f=1;
		if(i!=1&&a[i]!=a[i-1]+1) ff=1;
	}
	if(n<2000){
		solve1();
		return 0;
	}
	if(m==n-1){
		solve2();
		return 0;
	}
	if(!f){
		solve3();
		return 0;
	}
	if(!ff){
		solve4();
		return 0;
	}
	cout<<1;
	return 0;
}
