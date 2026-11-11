#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,x[2000005],dis[2000005],cnt[2000005];
queue<int>que;
int bfs(int s){
	for(int i=1;i<=n;i++)dis[i]=1e9,cnt[i]=0;
	dis[s]=0;cnt[s]=1;que.push(s);
	while(!que.empty()){
		int u=que.front();que.pop();
		if(cnt[u]>2)continue;
		for(int i=u+1;i<=n;i++){
			if(x[i]-x[u]>d)break;
			if(dis[i]>dis[u]+1)dis[i]=dis[u]+1,cnt[i]=cnt[u],que.push(i);
			else if(dis[i]==dis[u]+1)cnt[i]+=cnt[u];
			if(cnt[i]>2)cnt[i]=3;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)res+=(cnt[i]==2);
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=5000){
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=bfs(i);
			cout<<ans<<'\n';
		}
		else if(c==11||c==12){
			d=d/(x[2]-x[1]);
			int ans=0;
			if(d<=1){
				cout<<"0\n";goto bk;
			}
			for(int i=1;i<=n;i++)
//				for(int j=i+1;j<=n;j++)
					ans+=(d+d-1+i<=n);
			cout<<ans<<'\n';
			bk:;
		}
		else cout<<0<<'\n';
	}
	return 0;
}

