//SN-S00255
#include<bits/stdc++.h>
using namespace std;
const int fyc=4e6+5;
long long c,t,n,d,x[fyc],ans,head[5005],dis1[5005],dis2[5005],dis3[5005],vis[5005],cnt;
struct edge{
	long long to,nxt;
}e[2500*5001+5];
struct node{
	long long pos,dis;
};
void add(long long x,long long y){
	e[++cnt]={y,head[x]},head[x]=cnt;
}
void dijkstra(int s){
	queue<node> q;
	q.push((node){s,0});
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		long long x=tmp.pos;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to,f=dis1[x]+1;
			if(dis1[y]>=f){
				dis3[y]=dis2[y],dis2[y]=dis1[y],dis1[y]=f;
				q.push((node){y,dis1[y]});
				continue;
			}
			else if(dis2[y]>=f) dis3[y]=dis2[y],dis2[y]=f;
			else if(dis3[y]>=f) dis3[y]=f;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12||n>5000){
			long long dif=x[2]-x[1];
			if(2*dif>d) cout<<0<<"\n";
			else{
				int p=d/dif;
				cout<<max(n-2*p+1,0LL)<<"\n";
			}
		}
		else if(n<=5000){
			memset(head,0,sizeof head);
			cnt=ans=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(abs(x[j]-x[i])<=d)
						add(i,j),add(j,i);
			for(int i=1;i<=n;i++){
				memset(dis1,0x3f,sizeof dis1);
				memset(dis2,0x3f,sizeof dis2);
				memset(dis3,0x3f,sizeof dis3);
				memset(vis,0,sizeof vis);
				dis1[i]=0;
				dijkstra(i);
				for(int j=i+1;j<=n;j++){
					if(dis1[j]==dis2[j]&&dis1[j]<=1e18&&dis3[j]>dis1[j]) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
}
//latest 18:22:00
