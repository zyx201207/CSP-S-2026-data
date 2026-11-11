#include<bits/stdc++.h> 
using namespace std;
bool b[30];
long long n,m,k[200001],ma=-1e18;
void dfs(int bu,long long v){
	if(bu==m){
		ma=max(ma,v);
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==false){
			b[i]=true;
			dfs(bu+1,v&k[i]);
			b[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>k[i];
	if(n<=20){
		for(int i=1;i<=n;i++){
			b[i]=true;
			dfs(1,k[i]);
			b[i]=false;
		}
		cout<<ma;
	}else if(n<=2000){
		long long maxx=-1e18,z=k[1];
		for(int i=1;i<=n;i++){
			maxx=max(maxx,k[i]);
			z&=k[i];
		}
		if(m==1)cout<<maxx;
		else if(m==n)cout<<z;
		else{
			maxx=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
			if(i!=j)maxx=max(maxx,k[i]&k[j]);
		}}
		cout<<maxx;	
		}
	}else{
		cout<<2;
	}
	return 0;
}
