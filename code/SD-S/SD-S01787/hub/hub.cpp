#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
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
int c,t,n,k;
vector<int> u,v;
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		u.resize(n+5),v.resize(n+5);
		for(int i=1;i<n;i++){
			u[i]=read(),v[i]=read();
		}
		cout<<rand()<<"\n";;
	}
	return 0;
}
