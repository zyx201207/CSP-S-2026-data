#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int c,t,n;
long long d,a[2000010],sum;
bool f;
int dis[2000010],cnt[2000010];
queue<pair<int,int> >q;
long long bfs(int x){
	long long ans=0;
	q.push({x,0});
	for(int i=x;i<=n;i++)cnt[i]=0,dis[i]=2000010;
	while(q.size()){
		int u=q.front().first,v=q.front().second;
		q.pop();
		if(v>dis[u])continue;
		cnt[u]=(v<dis[u]?1:cnt[u]+1),dis[u]=min(dis[u],v);
		for(int i=u+1;i<=n&&a[i]-a[u]<=d;i++)if(v<dis[i])q.push({i,v+1});
	}
	for(int i=x;i<=n;i++)if(cnt[i]==2)ans++;
	//cout<<x<<" "<<ans<<endl;
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		f=1;
		sum=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=2;i<=n&&f;i++)f=a[i]-a[i-1]==a[2]-a[1];
		if(f)printf("%lld\n",(a[2]-a[1]>=d?0:max(0ll,n-(d/(a[2]-a[1])*2-1))));
		else{
			for(int i=1;i<n;i++)sum+=bfs(i);
			printf("%lld\n",sum);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
