#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
ll read(){
	char c=getchar();
	ll l=1,ret=0;
	while(!isdigit(c))l=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*l;
}
void write(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=2e6+7;
ll c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();k=read();
		for(int i=1;i<n;i++){
			u=read();v=read();
		}
		write(n%2);
		putchar('\n');
	}
	return 0;
}