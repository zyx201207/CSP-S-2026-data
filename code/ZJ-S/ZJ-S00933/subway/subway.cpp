#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,ans,sum;
ll k[510],w[500010],a[510][1010],t[510][1010];
ll vis[500010];
ll mp[1010][1010];
void dfs(ll x,ll y){
	//cout<<sum<<" "<<x<<"\n";
	//if(x==127)cout<<"1\n";
	if(x==y){
		ans=min(ans,sum);
		return;
	}
	vis[x]=1;
	for(ll i=1;i<=m;i++){
		if(mp[x][i]!=0&&vis[i]==0){
			sum+=mp[x][i];
			dfs(i,y);
			sum-=mp[x][i];
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	if(m<=1000){
		for(ll i=1;i<=n;i++){
			cin>>k[i];
			for(ll j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				for(ll r=1;r<j;r++){
					if(mp[a[i][j]][a[i][r]]==0){
						mp[a[i][j]][a[i][r]]=t[i][j]+t[i][r];
						mp[a[i][r]][a[i][j]]=t[i][j]+t[i][r];
					}else{
						mp[a[i][j]][a[i][r]]=min(mp[a[i][j]][a[i][r]],t[i][j]+t[i][r]);
						mp[a[i][r]][a[i][j]]=min(mp[a[i][j]][a[i][r]],t[i][j]+t[i][r]);
					}
				}
			}
		}
		for(ll i=1;i<=q;i++){
			memset(vis,0,sizeof(vis));
			ll x,y;
			cin>>x>>y;
			ans=2e9;
			sum=0;
			ll kkk=x+y;
			x=max(x,y),y=kkk-x;
			dfs(x,y);
			ans=ans+w[x]+w[y];
			cout<<ans<<"\n";
		}
	}else{
		
	}
}