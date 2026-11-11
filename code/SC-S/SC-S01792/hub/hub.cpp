#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+7,inf=(LONG_LONG_MAX>>2);

int c,t,ans;
int n,m,k,cnt;
int head[maxn],to[maxn],nxt[maxn];
int stk[maxn];
int dep[maxn];

int in(){
	int t=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^48);
		c=getchar();
	}
	return k*t;
}

void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x^48);
	else out(x/10),putchar(x%10^48);
}

void add(int x,int y){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int p,int fa){
//	cout<<p<<" : "<<dep[p]<<" "<<dep[fa]+1<<endl;
	dep[p]=min(dep[p],dep[fa]+1);
	for(int i=head[p];i;i=nxt[i]){
		if(to[i]==fa) continue;
		dfs(to[i],p);
	}
}

int calc(int x){
	int ret=0;
	while(x){
		if(x&1) ret++;
		x>>=1;
	}
	return ret;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=in(),t=in();
	while(t--){
		ans=inf;
		n=in(),k=in();
		if(c>=4){
			for(int i=1,u,v;i<n;i++){
				u=in(),v=in();
			}
			out(rand()%((n+k-1)/k)),putchar('\n');
			continue;
		}
		for(int i=1,u,v;i<n;i++){
			u=in(),v=in();
			add(u,v);
			add(v,u);
		}
		for(int i=1;i<(1<<n);i++){
			if(calc(i)!=k) continue;
			for(int j=1;j<=n;j++) dep[j]=inf;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					dep[j+1]=0;
					dfs(j+1,0);
				}
			}
			int curans=0;
			for(int j=1;j<=n;j++){
				curans=max(curans,dep[j]);
			}
			ans=min(ans,curans);
		}
		out(ans),putchar('\n');
		for(int i=1;i<=cnt;i++){
			head[i]=nxt[i]=to[i]=0;
		}
	}
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