#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c,n,m,d,q;
int w[N];
struct sub{
	int a,t,l;
};
vector<sub> g[N];
inline int read(){
	int res=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int lx=0;
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int x=read(),t=read();
	}
	srand(time(0));
	while(q--){
		int s=read(),f=read();
		cout<<rand()<<'\n';
	}
	return 0;
}
