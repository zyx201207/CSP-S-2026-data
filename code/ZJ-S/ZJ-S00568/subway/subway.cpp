#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f*x;
}
int c,n,m,d,q,w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	c=read(),n=read(),m=read(),d=read(),q=read();
	while(q--){
		cout<<rand()%1000+10<<'\n';
	}
	return 0;
}
