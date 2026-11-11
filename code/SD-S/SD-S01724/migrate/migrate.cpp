#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void read(T &x){int f=1;char ch=getchar();x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}x=x*f;return;}

const int N=5005;
int c,t,n,d;
int a[N];
bool vis[N];
int tong[N];

void dfs(int x,int now,int st,int en){
	if(x==en){ 
		tong[now]++;
		return;
	}
	for(int i=x+1;i<=en;i++)
		if(a[x]+d>=a[i]&&!vis[i])
			dfs(i,now+1,st,en);
}
//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
void solve(){
	int ans=0;
	read(n),read(d);
	memset(tong,0,sizeof(tong));
	for(int i=1;i<=n;i++)read(a[i]);
	for(int st=1;st<=n;st++){
		for(int en=st+1;en<=n;en++){
			memset(tong,0,sizeof(tong));
			dfs(st,0,st,en);
			for(int i=1;i<=n;i++){
				if(tong[i]!=0){
					if(tong[i]==2)ans++;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(t);
	while(t--)solve();
}

