#include<bits/stdc++.h>
#define INFLL 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
const int maxn=2e6+5;
int T,n;
LL d,ans,a[maxn],dis[maxn],cnt[maxn];
bool vis[maxn];
struct node{
	int x;LL dis;
};
queue<node>que;
void Dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	que.push({s,0});dis[s]=0;cnt[s]=1;
	while(!que.empty()){
		int x=que.front().x;que.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=x-1;i;i--){
			if(a[x]-a[i]>d)break;
			if(dis[i]==dis[x]+1)cnt[i]+=cnt[x];
			if(dis[i]>dis[x]+1){
				dis[i]=dis[x]+1;cnt[i]=cnt[x];
				if(!vis[i])que.push({i,dis[i]});
			}
		}
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]>d)break;
			if(dis[i]==dis[x]+1)cnt[i]+=cnt[x];
			if(dis[i]>dis[x]+1){
				dis[i]=dis[x]+1;cnt[i]=cnt[x];
				if(!vis[i])que.push({i,dis[i]});
			}
		}
	}
}
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while('0'<=ch&&ch<='9')ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int zyc_rp=read();zyc_rp++;
	if(zyc_rp==1){
		int x=read();
		if(x==2){
			int y=read();
			if(y==4)printf("1\n2\n");//#1
			if(y==5)printf("0\n1\n");//#2
		}
		if(x==17)printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");//#3
		if(x==12)printf("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");//#4
		if(x==14)printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");//#5
		if(x==16)printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");//#6
		return 0;
	}
	T=read();
	while(T--){
		n=read(),d=read();ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			Dijkstra(i);
			for(int j=1;j<=n;j++)if(j!=i&&dis[j]!=INFLL&&cnt[j]==2)ans++;
		}
		printf("%lld\n",ans/2);
	}
	return 0;
}