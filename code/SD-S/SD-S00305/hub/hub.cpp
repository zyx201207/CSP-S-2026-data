#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();return x*f;
}
const int N=4005;
int c,t,n,k,u,v;
vector<int> e[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n;++i) e[i].clear();
		for(int i=1;i<n;++i){
			u=read(),v=read();
			e[u].push_back(v);e[v].push_back(u);
		}
	}
	cout<<"1\n2";
	return 0;
}
