#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);\
				freopen(x".out","w",stdout);
using namespace std;
const int N=3e6+5;
using pii=pair<int,int>;
int nxt[N],pre[N],cnt[N],qn,ln[N],rn[N];
struct edge{
	int to,nxt;
}e[N];
int tot,head[N];
int res=0,g[N],F[N],tim,top;
long long ans,x[N],timer;
pair<pii,pii> upd[N<<1];
void clear(int n){
	for(int i=1;i<=tot;i++) e[i].to=e[i].nxt=0;
	for(int i=1;i<=n;i++)
		nxt[i]=pre[i]=cnt[i]=head[i]=rn[i]=ln[i]=0,
		g[i]=1,F[i]=0;
	tot=res=top=0;
	ans=0;
}
void add(int x,int y){
	e[++tot]={y,head[x]};
	head[x]=tot;
}
void set_val(int n,int x){
	if(g[n]>=x){
		return ;
	}
	upd[++top]={{n,g[n]},{res,tim}};
	if(g[n]==1&&x==2){
		g[n]=2;
		res++;
		if(F[n]&&rn[n]){
			for(int i=ln[n];i<=rn[n];i++)
				set_val(i,2);
		}
		else if(!F[n]&&F[n-1]&&rn[n]){
			for(int i=ln[n];i<=rn[n];i++)
				set_val(i,3);
		}
	}
	if(g[n]==1&&x==3){
		g[n]=3;
		if(rn[n]){
			for(int i=ln[n];i<=rn[n];i++)
				set_val(i,3);
		}
	}
	if(g[n]==2&&x==3){
		g[n]=3;
		res--;
		if(rn[n]){
			for(int i=ln[n];i<=rn[n];i++)
				set_val(i,3);
		}
	}
}
void solve(int n,int lst){ // 解决 st~[n,N] 间的所有问题 
	if(n>qn) return;
	int latim=tim;
	tim=n;
	F[n]=1;
//	cout<<"test "<<n<<'\n';
//	for(int i=1;i<=n;i++) if(F[i]) cout<<i<<' ';cout<<'\n';
	if(F[lst+1]==0&&rn[lst+1]){
		for(int i=ln[lst+1];i<=rn[lst+1];i++)
			set_val(i,g[lst+1]+1);
	}
//	cout<<"ans[1,"<<n<<"]="<<res<<'\n';
	ans+=res;
	for(int i=head[n];i;i=e[i].nxt)
		solve(e[i].to,n);
	while(top&&upd[top].second.second==n){
		pii tp=upd[top].first;
		g[tp.first]=tp.second;
		res=upd[top].second.first;
		top--;
	}
	F[n]=0; 
	tim=latim;
}
void work(){
	int n;long long d;
	cin>>n>>d; qn=n;
	clear(n);
	for(int i=1;i<=n;i++) cin>>x[i];
	int pt=1;
	for(int i=1;i<=n;i++){
		while(pt<i&&x[i]-x[pt]>d) pt++;
		pre[i]=pt;
		if(pt!=i) add(pt,i);
	}
	pt=n;
	for(int i=n;i>=1;i--){
		while(pt>i&&x[pt]-x[i]>d) pt--;
		nxt[i]=pt;
	}
	for(int i=1;i<=n;i++)
		if(nxt[i]!=i) rn[nxt[i]]=i;
	for(int i=n;i>=1;i--)
		if(nxt[i]!=i) ln[nxt[i]]=i;
//	for(int i=1;i<=n;i++) cout<<ln[i]<<' '<<rn[i]<<'\n';
	for(int i=1;i<=n;i++)
		if(pre[i]==i)
			solve(i,0);
	cout<<ans<<'\n';
}
signed main(){
	file("migrate");
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
		work();
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
7 6
-10 -5 -1 1 3 5 9
*/
