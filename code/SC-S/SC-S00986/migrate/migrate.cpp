#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+3;
int c,t;
int n;
ll ans;
ll d;
ll x[N];
map<int,int> cl;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void dfs(int l,int y,int sum){
	if(l==y){
		cl[sum]++;
		return ;
	}
	for(int i=l+1;i<=y;i++){
		if(x[i]>x[l]+d) break;
		dfs(i,y,sum+1);
	}
}
inline int check(int x,int y){
	cl.clear();
	dfs(x,y,0);
	int minn=N,cnt=0;
	for(auto i:cl){
		if((i.first)<minn){
			minn=i.first;
			cnt=i.second;
		}
	}
	if(cnt==2) return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	if(c>=11&&c<=12){
		while(t--){
			n=read();d=read();
			for(int i=1;i<=n;i++) x[i]=read();
			ll gc=x[2]-x[1];
			ll ans=0;
			ll man=d/gc*2-1;
			if(man>n||d<gc*2){
				write(0);putchar('\n');
			}else{
				write(n-man);putchar('\n');
			}
		}
		return 0;
	}
	while(t--){
		n=read();d=read();
		ans=0;
		for(int i=1;i<=n;i++) x[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)) ans++;
			}
		}
		write(ans);putchar('\n');
	}
	return 0;
}