#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int x[100010];
int mp[1000][1000];
int dv[1000];
bool vis[1000];
int v[1000];
int w[1000];
int ans;
void f(int now,int y,int sum){
	if(now==y || sum>ans){
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=m;i++){
		if(mp[now][i]){
			if(!vis[i]){
				vis[i]=1;
				f(i,y,mp[now][i]+sum);
				vis[i]=0;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
		int a[1000],t[1000];
		for(int j=1;j<=x[i];j++){
			cin>>a[j]>>t[j];
			if(dv[a[j]]==0){
				dv[a[j]]=i;
			}
			v[a[j]]=t[j];
		}
		for(int j=1;j<x[i];j++){
			mp[a[j]][a[j+1]]=v[a[j]]+v[a[j+1]];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=INT_MAX;
		f(x,y,w[x]);
		cout<<ans+w[y]<<endl;
	}
	return 0;
}