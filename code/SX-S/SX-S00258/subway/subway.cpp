#include<bits/stdc++.h>
using namespace std;
const int N=505,M=2e4+5;
int val[M],m,n,cnt=1,k[N],head[N+M];
long long dis[N][M];
bool f[N+M];
priority_queue<pair<int,int> >q;
struct node{
	int to,net,w;
}a[M*2];
inline void add(int u,int v,int w){
	a[cnt].net=head[u];
	a[cnt].to=v;
	a[cnt].w=w;
	head[u]=cnt++;
	return;
}
void D(int s){
	for(int i=0;i<=m+n;i++){
		dis[s][i]=0x3f3f3f3f,f[i]=false;
	}
	while(!q.empty())q.pop();
	q.push(make_pair(0,s));
	dis[s][s]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(f[x])continue;
		f[x]=true;
		for(int i=head[x];i;i=a[i].net){
			int y=a[i].to;
			if(dis[s][y]>dis[s][x]+a[i].w){
				dis[s][y]=dis[s][x]+a[i].w;
				q.push(make_pair(-dis[s][y],y));
			}
		}
	}
	return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0),cin.tie(0);
    int c,d,qu;
    cin>>c>>n>>m>>d>>qu;
    for(int i=1;i<=m;i++){
    	cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		int v,w;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>v>>w;
			add(i,v+n,w),add(v+n,i,w);
		}
	}
	for(int i=1;i<=n;i++){
		D(i);
//		for(int j=head[i];j;j=a[j].net){
//			cout<<i<<" "<<a[j].to<<" "<<dis[i][a[j].to]<<"\n";
//		}
	}
//	cout<<"\n";
	for(int kk=1;kk<=qu;kk++){
		int u,v;
		long long ans=LLONG_MAX/2;
		cin>>u>>v;
		for(int i=head[u+n];i;i=a[i].net){
			ans=min(ans,dis[a[i].to][v+n]+a[i].w);
//			cout<<a[i].to<<" "<<v<<" "<<dis[a[i].to][v+n]<<"\n";
		}
		cout<<ans+val[u]+val[v]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
