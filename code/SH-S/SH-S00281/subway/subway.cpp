#include <bits/stdc++.h>
using namespace std;
#define int long long
void read(long long &a){
	a=0;
	char c;
	do{c=getchar();if(c>='0'&&c<='9') break;}while(1);
	while(c>='0'&&c<='9'){
		a*=10;a+=c-'0';c=getchar();
	}
}
int head[1000010];
int edge[1000010];
int val[1000010];
int nxt[1000010];
int w[1000010];
int vis[1000010];
int dp[1010][1010];
int c,n,m,d,q;
int idx;
int ei;
void add(int id,int u,int v,int w){
	nxt[id]=head[u];
	head[u]=id;
	edge[id]=v;
	val[id]=w;
}
#define add1(id,u,v,w) add(id*2,u,v,w);add(id*2+1,v,u,w);
int bfs(int from,int to){
	queue<int> q;
	q.push(from);
	for(int i=1;i<=idx;++i) vis[i]=0;
	vis[from]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int i;
		for(int j=head[x];j;j=nxt[j]){
			i=edge[j];
			if(vis[i]) continue;
			vis[i]=vis[x]+1;
			if(i==to){
				return vis[to]-1;
			}
			q.push(i);
		}
	}
	return 0;
}
int argu,dest;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;++i){
		read(w[i]);
	}
	idx=m;
	for(int i=1;i<=n;++i){
		int kkk=0;
		int aaa=0,bbb=0,ccc=0,ddd=0;
		read(kkk);
			++idx;
		for(int j=1;j<=kkk;++j){
			read(aaa);
			read(bbb);
			ccc=aaa,ddd=bbb;
	//		printf("aaa=%d,bbb=%d\n",aaa,bbb);
			if(c<=8){
				do{
					ei++;
					add1(ei,idx,aaa,bbb);
				}while(0);
			}else{
				if(j!=1){
					ei++;
					add1(ei,ccc,aaa,bbb+ddd);
				}
			}
		}
	}
	if(c<=11){//floyd
//	cout<<1;
		if(c>8) idx=m;
		for(int i=1;i<=idx;++i){
			for(int j=1;j<=idx;++j){
				dp[i][j]=0x7f7f7f7f7f7f7f;
			}
			dp[i][i]=0;
		}
		for(int i=1;i<=idx;++i){
			for(int j=head[i];j;j=nxt[j]){
				dp[i][edge[j]]=min(dp[i][edge[j]],val[j]);
			}
		}
		if(c<=8){
			for(int i=1;i<=idx;++i){
				for(int j=1;j<=idx;++j){
					dp[j][j]=0;
					for(int k=1;k<=idx;++k){
						dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
					}
				}
			}
		}
		for(int i=1;i<=q;++i){
			read(argu);
			read(dest);
			printf("%lld\n",dp[argu][dest]+w[argu]+w[dest]);
		}
		return 0;
	}else{
		int www=val[2];
		for(int i=1;i<=q;++i){
			read(argu);
			read(dest);
			printf("%lld\n",bfs(argu,dest)*www+w[argu]+w[dest]);
		}
	}
	return 0;
}
//I'm the SH-J00254
//Was the Cash Collection Foundation want to create an director app?
//I'm a qu that I can't AK CSP-J2026
//there is a splay
//    a
//   / \
//  p   y
// / \
//s   l

//and rotate(y)
//      y
//     /
//    a
//   /
//  p
// / \
//s   l

//and rotate(l)
//        y
//       /
//      a
//     /
//    l
//   /
//  p
// /
//s

//then we do splay(s,0)

//first rotate(p)
//      y
//     /
//    a
//   /
//  p
// / \
//s   l

//rotate(s)
//    y
//   /
//  a
// /
//s
// \
//  p
//   \
//    l

//rotate(a)
//  a
// / \
//s   y 
// \
//  p
//   \
//    l

//rotate(s)
//s
// \
//  a
// / \
//p   y
// \
//  l


//finally I want to ask you
//can you write a splay?



//it's 18:03
//teacher told us that the subway sample2 emplaints wrong.
