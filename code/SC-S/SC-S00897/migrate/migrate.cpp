#include<bits/stdc++.h>
using namespace std;
#define fo(i,begin,end) for(int i=begin;i<=end;++i)
#define of(i,begin,end) for(int i=begin;i>=end;--i)
#define ll long long
const int N=2e6+5,M=5000;
int c,t,n,ans;
ll d,a[N],dis[M+5],cnt[M+5];
vector<int> G[M];
void dfs(int s,int u,int res){
	if(u==s){
		fo(j,u+1,n){
			if(a[j]-a[u]<=d) dfs(s,j,res+1);
			else break;
		}
	}else{
		fo(j,u+1,n){
			if(a[j]-a[u]<=d){
				if(dis[j]>res+1) dis[j]=res+1,cnt[j]=1;
				else if(dis[j]==res+1) cnt[j]++;
				dfs(s,j,res+1);
			}else break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,ans=0;
		fo(i,1,n) G[i].clear();
		fo(i,1,n) cin>>a[i];
		fo(i,1,n) fo(j,i+1,n) if(a[j]-a[i]<=d) G[i].push_back(j);
		fo(i,1,n){
			fo(j,i,n){
				if(a[j]-a[i]<=d) dis[j]=a[j]-a[i],cnt[j]=1;
				else dis[j]=1e18,cnt[j]=0;
			}
			dfs(i,i,1);
			fo(j,i,n) if(cnt[j]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}