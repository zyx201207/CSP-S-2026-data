#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
inline int qread(){
	#define qr qread()
	int x=0,c=getchar(),t=1;
	while(c<'0'||c>'9'){
		t^=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return (t?x:-x);
} 
inline void qwrite(int x){
	#define qw(_) qwrite(_)
	#define qws(_) qw(_),putchar(' ')
	#define qwe(_) qw(_),putchar('\n')
	if(x<0) x=-x,putchar('-');
	if(x>9) qw(x/10);
	putchar(x%10+'0');
	return;
}
vector<int>e[N];
int f[N];
bool vis[N];
int find(int x){
	return (f[x]==x?x:f[x]=find(x));
}
void merge(int x,int y){
	x=find(x);y=find(y);
	f[y]=x;
	return;
}
void dfs(int s,int x,int fa){
	for(int i=0;i<e[x].size();i++){
		int v=e[x][i];
		if(v==fa) continue;
		
	}
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=qr,T=qr;
	while(T--){
		int n=qr,k=qr;
		for(int i=2;i<=n;i++){
			int u=qr,v=qr;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++) f[i]=i;
		for(int s=0;s<(1<<n);s++){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s&(1<<(i-1))){
					cnt++;
				}
			}
			if(cnt==k){
				int last=0;
				for(int i=1;i<=n;i++){
					if(s&(1<<(i-1))){
						dfs(s,i,0);
					}
				}
			}
		}
	}
	return 0;
}
