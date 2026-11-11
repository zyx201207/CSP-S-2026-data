#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050],ma,len;
bool dis[200050];
void dfs(int pos,int b,int step){
	if(b<ma){
		return;
	}
	if(step==m){
		ma=max(ma,b);
		return;
	}int l=n-m+step+1;
	for(int i=pos+1;i<=l;i++){
		if(dis[i]==0){
			dis[i]=1;
			dfs(i,b&a[i],step+1);
			dis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	ma=0;
	len=n-m+1;
	for(int i=1;i<=len;i++){
		dis[i]=1;
		dfs(i,a[i],1);
		dis[i]=0;
	}cout<<ma;
	return 0;
}
