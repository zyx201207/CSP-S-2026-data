#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010],minn=1e9,ans,cnt;
void dfs(int u,int v,int p){
	if(u==v){
		minn=min(minn,p);
		return;
	}
	if(u>v||u==n)return;
	for(int i=u+1;i<=n;i++){
		if(x[i]-x[u]<=d)dfs(i,v,p+1);
	}
}
void dfss(int u,int v,int p){
	if(u==v){
		if(p==minn)ans++;
		return;
	}
	if(u>v||u==n)return;
	for(int i=u+1;i<=n;i++){
		if(x[i]-x[u]<=d)dfss(i,v,p+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				minn=1e9;
				dfs(i,j,0);
				if(minn!=1e9){
					ans=0;
					dfss(i,j,0);
					if(ans==2)cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
}
//gugugaga gugugaga gugugaga!!!
