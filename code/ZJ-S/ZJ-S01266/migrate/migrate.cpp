#include<bits/stdc++.h>
using namespace std;
long long c,t,n,a[2000005],d,sud,fg;
bool bfs(long long st,long long ed){
	int vis[305],cnt[305];
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	queue<pair<long long,long long> > q;
	q.push({st,0});
	long long minn=-1;
	cnt[st]=1;
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		long long op=p.first,dis=p.second;
		if(op==ed){
			return cnt[op]==2;
		}
		vis[op]=1;
		long long nxt=op+1;
		while(nxt<=ed&&a[nxt]-a[op]<=d){
			if(vis[nxt]==0||vis[nxt]==dis+1){
				q.push({nxt,dis+1});
				vis[nxt]=dis+1;
				cnt[nxt]++;
			} 
			nxt++;
		}
	}
	return cnt[ed]==2;
}
void baol(){
	long long ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(bfs(i,j)){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		sud=a[2]-a[1];
		fg=1;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=sud){
				fg=0;
				break;
			}
		}
		baol();
	}
}
