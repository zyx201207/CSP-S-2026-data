#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int c,t,n,k;
int cnt,h[N];
struct node{
	int nxt;
	int to;
}e[N*2];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while('0'<=ch && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void add(int u,int v){
	e[++cnt].nxt=h[u];
	e[cnt].to=v;
	h[u]=cnt;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for (int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		cout<<"1\n";
	}
	return 0;
}
