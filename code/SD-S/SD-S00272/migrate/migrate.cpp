#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+7;
int T,n,c;
ll d,a[N],ans;
ll dis[N];
ll cnt[N];
bool vis[N];
unsigned ll f(int i,int j){
	if(a[i]<0&&a[j]>0)return 1ull*(-a[i])+a[j];
	else return a[j]-a[i];
}
ll bfs(int s){
	queue<ll>q;
	for(int i=1;i<=n;i++){
		dis[i]=-1;
		cnt[i]=0;
		vis[i]=0;
	}
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		int u=q.front();
		//cout<<u<<"\n";
		q.pop();
		for(int i=u+1;i<=n;i++){
			//cout<<f(u,i)<<"\n";
			if(a[u]+d>=a[i]){
				if(dis[i]==-1){
					dis[i]=dis[u]+1;
					cnt[i]=cnt[u];
					q.push(i);
				}
				else if(dis[u]+1==dis[i])cnt[i]++;
			}
			//else break;
		}
	}
	ll res=0;
	for(int i=s;i<=n;i++){
		//cout<<cnt[i]<<" "<<dis[i]<<" ";
		res+=(cnt[i]==2);
	}
	//cout<<"\n";
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++)f[i]
//		}
		for(int i=1;i<=n;i++)ans+=bfs(i);
		cout<<ans<<"\n";
	}
	return 0;
}
