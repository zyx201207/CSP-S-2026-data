#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
ll readl(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int c,t,n;
ll d,x[N],res,minn,cnt;
void bfs(int u,int v){
	queue<ll> qu;
	qu.push(u);
	bitset<N> vis;
	vis[(unsigned long long)u]=1;
	while(!qu.empty()){
		ll y=qu.front();
		qu.pop();
		if(cnt>2){
			return ;
		}
		if(y==v){
			++cnt;
			continue;
		}
		for(int j=y+1;j<=n;++j){
			if(!vis[(unsigned long long)j]&&x[j]-x[y]<=d&&x[j]<=v){
				vis[(unsigned long long)j]=1;
				qu.push(j);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	for(int _=1;_<=t;++_){
		n=read();
		d=readl();
		for(int i=1;i<=n;++i){
			x[i]=readl();
		}
		if(c<=2){
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					cnt=0;
					bfs(i,j);
					if(cnt==2){
						++res;
					}
				}
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}

