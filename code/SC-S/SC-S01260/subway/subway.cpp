#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int c,n,m,d,q,st,ed,ans=0x7f7f7f7f;
int w[N],k[N],a[1000][1000],r[1000][1000],viss[1000],vis[1000][1000];
bool exi(int s,int x){
	for(int i=1;i<=k[s];i++){
		if(a[s][i]==x)return 1;
	}
	return 0;
}
void dfs(int x,int s,int sum){
//	cout<<x<<" "<<s<<" "<<sum<<"\n";
	if(x==ed){
		ans=min(ans,sum+w[ed]+r[s][ed]);
//		cout<<r[s][ed]<<"  1   1  "<<ans<<"\n";
		return;
	}
	if(sum>ans)return;
//	cout<<x<<" "<<s<<" "<<sum<<"\n";
	for(int i=1;i<=n;i++){
		if(i==s)continue;
		if(viss[i]==0&&exi(i,x)){
			viss[i]=1;
			vis[i][x]=1;
			dfs(x,i,sum+r[s][x]+r[i][x]);
			viss[i]=0;
			vis[i][x]=0;
		}
	}
	for(int i=1;i<=k[s];i++){
		if(a[s][i]==x)continue;
		if(vis[s][a[s][i]]==0){
			vis[s][a[s][i]]=1;
			dfs(a[s][i],s,sum);
			vis[s][a[s][i]]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>r[i][a[i][j]];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		ans=0x7f7f7f7f;
		for(int i=1;i<=n;i++){
			if(exi(i,st)){
				viss[i]=1;
				vis[i][st]=1;
				dfs(st,i,w[st]+r[i][st]);
				vis[i][st]=0;
				viss[i]=0;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}