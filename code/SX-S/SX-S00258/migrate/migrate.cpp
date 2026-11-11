#include<bits/stdc++.h>
using namespace std;
const int N=305;
int x[N],head[N],cnt=1,n,ans,dis[N],sum[N];
struct node{
	int to,net,w;
}a[N*N*2];
inline void add(int u,int v,int w){
	a[cnt].net=head[u];
	a[cnt].to=v;
	a[cnt].w=w;
	head[u]=cnt++;
	return;
}
bool f[N];
priority_queue<pair<int,int> >q;
void D(int s){
	for(int i=s;i<=n;i++){
		dis[i]=0x3f3f3f3f,f[i]=0,sum[i]=0;
	}
	while(!q.empty())q.pop();
	q.push(make_pair(0,s));
	dis[s]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(f[x])continue;
		f[x]=true;
		for(int i=head[x];i;i=a[i].net){
			int y=a[i].to;
			if(dis[y]>dis[x]+a[i].w){
				dis[y]=dis[x]+a[i].w,sum[y]=1;
				q.push(make_pair(-dis[y],y));
			}
			else if(dis[y]==dis[x]+a[i].w)sum[y]++;
		}
	}
	for(int i=s;i<=n;i++){
		if(sum[i]==2)ans++;
	}
	return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long d;
		ans=0,cnt=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i],head[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)add(i,j,1);
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			D(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
