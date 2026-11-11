#include<bits/stdc++.h>
#define int long long
#define CK_TM cerr<<(double)1.0*abs(&ENDM-&STARTM)/(1024*1024)<<"MB"<<'\n'
bool STARTM;
namespace EVA{
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-') f^=1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		return f?x:~x+1;
	}
	inline void write(int x){
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar((x%10)^48);
	}
	inline void spaceput(int x){
		write(x);putchar(' ');
	}
	inline void output(int x){
		write(x);putchar('\n');
	}
}
using namespace EVA;
using namespace std;
const int inf=1e18;
const int N=2e6+5;
const int M=5e3+5;
int Case,T,n,d,ans,res,mn,tot=1,cur=0;
int s[N],head[N],dis[3][M];
bitset<N> vis,ovo; 
struct edge{
	int to,val,next;
}e[M*M];
struct node{
	int idx,w;
	inline friend bool operator < (node A,node B){
		return A.w>B.w;
	}
};
priority_queue<node> q;
inline void addedge(int u,int v,int w){
	tot++;e[tot].to=v;e[tot].val=w;e[tot].next=head[u];
	head[u]=tot;
}
inline void CCC(){
//	for(int i=0;i<=tot+1;i++) e[i].to=e[i].val=e[i].next=0;
	for(int i=0;i<=n+1;i++) head[i]=0;
	ans=0;
}
inline void dijkstra(int s){
	while(!q.empty()) q.pop();
	for(int i=0;i<3;i++) for(int j=1;j<=n;j++) dis[i][j]=inf;
	vis.reset();
	dis[0][s]=dis[1][s]=dis[2][s]=0;q.push({s,0});
	while(!q.empty()){
		int u=q.top().idx;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to,w=e[i].val;
//			int flag=0;
//			for(int o=0;o<2;o++){
				int o=0;
//				for(int k=0;k<3;k++){
//					if(o<=k&&dis[k][v]==-1||dis[k][v]>dis[o][u]+w){
//						for(int p=2;p>k;p--) dis[p][v]=dis[p-1][v];
//						dis[k][v]=dis[o][u]+w;
//						if(!k) flag=1;
//						break;
//					}
//				}
//				if(dis[0][v]==-1){
//					dis[0][v]=dis[o][u]+w;
//					q.push({v,dis[0][v]});
//				}
//				else if(dis[1][v]==-1){
//					dis[1][v]=dis[o][u]+w;
//					q.push({v,dis[1][v]});
//				}
//				else if(dis[2][v]==-1){
//					dis[2][v]=dis[o][u]+w;
//					q.push({v,dis[2][v]});
//				}
//				else{
					if(dis[0][v]>dis[o][u]+w){
						dis[2][v]=dis[1][v];dis[1][v]=dis[0][v];
						dis[0][v]=dis[o][u]+w;
						q.push({v,dis[0][v]});
					}
					else if(dis[1][v]>dis[o][u]+w){
						dis[2][v]=dis[1][v];
						dis[1][v]=dis[o][u]+w;
						q.push({v,dis[1][v]});
					}
					else if(dis[2][v]>dis[o][u]+w){
						dis[2][v]=dis[o][u]+w;
						q.push({v,dis[2][v]});
					}
//				}
//			}
//			if(flag==1){
//				for(int k=0;k<3;k++){
//					q.push({v,dis[k][v]});
//				}
//			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==s) continue;
		if(dis[0][i]==dis[1][i]&&dis[0][i]!=-1&& dis[0][i]!=dis[2][i]){
			ans++;
//			cout<<s<<" "<<i<<' '<<dis[0][i]<<" "<<dis[1][i]<<' '<<dis[2][i]<<"\n";
		}
	}
}
inline void spj0(){
	CCC();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(s[i]-s[j])<=d) addedge(i,j,1),addedge(j,i,1);
		}
	}
	for(int i=1;i<=n;i++) dijkstra(i);
	output(ans/2);
}
void dfs(int u,int ed,int cnt){
	if((cnt>=mn&&u!=ed)||cnt>mn) return;
	if(u==ed){
		if(cnt<mn){
			res=1;mn=cnt;
		}
		else if(mn==cnt) cur++,res++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(ovo[i]||i==u||abs(s[i]-s[u])>d) continue;
		ovo[i]=1;dfs(i,ed,cnt+1);
		ovo[i]=0;
	}
}
inline void SSS(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mn=inf;cur=0;ovo.reset();
			res=0;ovo[i]=1;dfs(i,j,0);
			if(res==2){
//				cout<<i<<" "<<j<<'\n';
				ans++;
			}
		}
	}
	output(ans);
}
bool ENDM;
signed main(){
//	system("fc migrate4.ans migrate.out");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	Case=read(),T=read();
	while(T--){
		n=read(),d=read(); 
		for(int i=1;i<=n;i++) s[i]=read();
		int sum=s[2]-s[1];
//		SSS();
		if(n<=10) SSS();
		else if(Case<=10) spj0();
		else if(Case>=11&&Case<=12){
			int curc=0;
			for(int i=4;i<=n;i+=2){
				int mid=i/2;
				if(sum*mid<=d&&sum*(mid+1)>d) curc+=n-i+1; 
			}
			output(curc);
		}
		else{
			cout<<0<<'\n';
		}
//		if(Case<=6) FFF();
	}
//	CK_TM;
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
