#include <bits/stdc++.h>
using namespace std;
long long GM,T,n,ans,d,a[2000010],sl[2000010],dis[2000010],vis[2000010];
queue<long long>q;
void bfs(long long x){
	long long i;
	for(i=1;i<=n;i++) dis[i]=2e9,sl[i]=0;
	q.push(x);sl[x]=1;dis[x]=0;
	while(!q.empty()){
		long long fx=q.front();q.pop();
		vis[fx]=0;
		long long t=fx+1,w=n,bao=-1;
		while(t<=w){
			long long mid=(t+w)/2;
			if(a[mid]-a[fx]<=d) bao=mid,t=mid+1;
			else w=mid-1;
		}
		for(i=x+1;i<=bao;i++)
			if(dis[fx]+1==dis[i]) sl[i]+=sl[fx];
			else if(dis[fx]+1<dis[i]){
				dis[i]=dis[fx]+1;
				sl[i]=sl[fx];
				if(!vis[i]) vis[i]=1,q.push(i);
			}
	}
	for(i=1;i<=n;i++){
		if(sl[i]==2){ans++;
		}
	}
}
void bfa(long long x){
	long long i;
	for(i=1;i<=n;i++) dis[i]=2e9,sl[i]=0;
	q.push(x);sl[x]=1;dis[x]=0;
	while(!q.empty()){
		long long fx=q.front();q.pop();
		vis[fx]=0;
		long long t=fx+1,w=n,bao=-1;
		while(t<=w){
			long long mid=(t+w)/2;
			if(a[mid]-a[fx]<=d) bao=mid,t=mid+1;
			else w=mid-1;
		}
		for(i=x+1;i<=bao;i++)
			if(dis[fx]+1==dis[i]) sl[i]+=sl[fx];
			else if(dis[fx]+1<dis[i]){
				dis[i]=dis[fx]+1;
				sl[i]=sl[fx];
				if(!vis[i]) vis[i]=1,q.push(i);
			}
	}
	for(i=1;i<=n;i++)
		if(sl[i]==2){
			int gc=i-1;
			ans=ans+n-gc;
		}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>GM>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(long long i=1;i<=n;i++) cin>>a[i];
		if(GM==11||GM==12) bfa(1);
		else for(long long i=1;i<=n;i++) bfs(i);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
pts=50
ÆÀ²â»ú±£ÓÓÎÒ 
*/
