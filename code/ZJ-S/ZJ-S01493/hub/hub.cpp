#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=305;//log2(N)=9
const LL inf=1e17;
LL in(){
	LL aa=0,bb=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){
		if(cc=='-')	bb=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		aa=(aa<<3)+(aa<<1)+(cc^48);
		cc=getchar();
	}
	return aa*bb;
}
void out(LL aa){
	if(aa<0){
		aa=-aa;
		putchar('-');
	}
	if(aa<=9)	putchar(aa+'0');
	else{
		out(aa/10);
		putchar(aa%10+'0');
	}
	return ;
}

vector<LL> mp[N];
LL dep[N],fa[N][20],x[N],ans;
bool flag[N];
LL lca(LL x,LL y){
	if(x==y)	return x;
	if(dep[x]<dep[y])	swap(x,y);
	for(int j=9;j>=0;j--){
		if(dep[fa[x][j]]>=dep[y]){
			x=fa[x][j];
		}
	}
	if(x==y)	return x;
	for(int j=9;j>=0;j--){
		if(fa[x][j]!=fa[y][j]){
			x=fa[x][j],y=fa[y][j];
		}
	}
	return fa[x][0];
}
LL bing[N];

void dfs(LL u,LL f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=0;i<mp[u].size();i++){
		LL v=mp[u][i];
		if(v==f)	continue;
		dfs(v,u);
	}
	return ;
} 
void DF(LL pos,LL k,LL n){
	if(pos==k+1){
		//printf("#");for(int i=1;i<=k;i++)	printf("%lld ",x[i]);printf("\n");
		LL cnt=0;

		for(int i=1;i<=n;i++){
			if(flag[i])	continue;
			LL t=inf;
			for(int j=1;j<=n;j++){
				if(!flag[j])	continue;
				LL LCA=lca(i,j);
				t=min(t,dep[i]+dep[j]-dep[LCA]*2);
			}
			cnt=max(cnt,t);
		}
		//printf("cnt=%lld\n ",cnt);
		ans=min(ans,cnt);
		return ;
	}
	for(int i=x[pos-1]+1;i<=n;i++){
		x[pos]=i;
		flag[i]=1;
		DF(pos+1,k,n);
		x[pos]=0; 
		flag[i]=0;
	}
	return;
}
void solve(){
	ans=inf;
	LL n=in(),k=in();
	for(int i=1;i<=n;i++)	mp[i].clear();
	for(int i=1;i<=n-1;i++){
		LL u=in(),v=in();
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1,0);
	for(int j=1;j<=9;j++){
		for(int i=1;i<=n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	DF(1,k,n);
	out(ans);
	putchar('\n'); 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	LL c=in(),T=in();
	while(T--)	solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
