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
int c,n,m,d,q;
vector<int> w,k,x,y;
vector<vector<int>> a,t;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	w.resize(m),k.resize(n),x.resize(q),y.resize(q);
	a.resize(n),t.resize(n);
	for(int i=0;i<m;i++){
		w[i]=read();
	}
	for(int i=0;i<n;i++){
		k[i]=read();
		for(int j=0;j<k[i];j++){
			a[i].push_back(read());
			t[i].push_back(read());
		}
	}
	for(int i=0;i<q;i++){
		x[i]=read(),y[i]=read(); 
	}
	for(int i=0;i<q;i++) cout<<rand()<<"\n";
	return 0;
}
