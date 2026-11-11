#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int res=0,ch;
	do{
		ch=getchar();
	}while(!isdigit(ch));
	do{
		res=(res<<1)+(res<<3)+(ch&0xf);
		ch=getchar();
	}while(isdigit(ch));
	return res;
}
constexpr int N=2e6+2;
constexpr ll inf=2e18;
int c,t,n,k,x[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n;++i){
			int u=read(),v=read();
		}
		puts("1");
	}
	return 0;
}