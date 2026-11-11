#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=205+5;
ll c,T,n,d,x[N],mn,ans,sum;
vector<int>g[N];
void dfs(int fa,int st,int ed,int cnt){
	if(st==ed){
		if(mn>cnt)mn=cnt,ans=1;
		else if(mn==cnt)ans++;
		return ;
	}
	for(auto u:g[st]){
		if(u==fa||cnt+1>mn)continue;
		dfs(st,u,ed,cnt+1);
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=30){
			for(int i=1;i<=n;i++)g[i].clear();
			sort(x+1,x+n+1);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j)continue;
					if(abs(x[i]-x[j])<=d){
						int w=abs(x[i]-x[j]);
						g[i].push_back(j);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j)continue;
					mn=1e9,ans=0;
					dfs(0,i,j,0);
					if(ans==2)sum++;
				}
			}
			cout<<sum<<"\n";
		}else{
			sort(x+1,x+n+1);
			for(int i=1;i<=n;i++){
				if(x[i+3]-x[i]<=2*d&&x[i+1]-x[i]<=d&&x[i+3]-x[i-2]<=d&&x[i+2]-x[i+1]<=d)sum++;
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}