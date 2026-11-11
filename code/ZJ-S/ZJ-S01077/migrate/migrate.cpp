#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],up[N],dis[N],cnt[N];
struct Node{
	long long x,w;
	bool operator<(const Node& ot)const{
		return w>ot.w;
	}
};
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		up[i]=upper_bound(a+i+1,a+1+n,a[i]+d)-a-1;
	}
	int ans=0;
	priority_queue<Node> q;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			dis[i]=0x3f3f3f3f,cnt[i]=0;
		}
		dis[i]=0,q.push({i,0});
		while(!q.empty()){
			Node u=q.top(); q.pop();
			if(u.w!=dis[u.x]) continue;
			for(long long j=u.x+1;j<=up[u.x];j++){
				if(dis[j]>1+dis[u.x]){
					dis[j]=1+dis[u.x],cnt[j]=1;
					q.push({j,dis[j]});
				}else if(dis[j]==dis[u.x]+1) cnt[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(cnt[i]==2) ans++;
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
