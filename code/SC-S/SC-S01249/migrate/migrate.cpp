#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x=0,t=1;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')t=-t;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*t;
}
inline void out(int x){
	if(x<0)putchar('-'),x=-x;
	char stk[30];int top=0;
	do{stk[++top]=(x%10)^48;x/=10;}while(x>0);
	while(top)putchar(stk[top--]);
}

const int zj=1e5+10;
int c,t,n,d,num[zj],ds[zj],ans;
int x[zj];

inline void dfs(int u,int dis){
	if(dis==ds[u])++num[u];
	else if(dis<ds[u])num[u]=1,ds[u]=dis;
	for(int i=u+1;i<=n;++i){
		if(x[i]-x[u]>d)break;
		dfs(i,dis+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in(),t=in();
	while(t--){
		n=in(),d=in();
		ans=0;
		for(int i=1;i<=n;++i)x[i]=in(),ds[i]=1234567;
		for(int i=1;i<=n;++i){
			dfs(i,1);
			for(int j=1;j<=n;++j){
				if(num[j]==2)++ans;
				num[j]=0;
				ds[j]=1234567;
			}
		}
		out(ans);
		puts("");
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/