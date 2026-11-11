#include<bits/stdc++.h>
#define up(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define dn(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}
int n,m;
vector<int> v,maxx;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	v.resize(n+1);
	maxx.assign(m+1,-1);
	up(i,1,n,1){
		v[i]=read();
	}
	up(i,1,m,1){
		int pos;
		up(j,1,n,1){
			if(maxx[i]<v[j]){
				maxx[i]=v[j];
				pos=j;
			}
		}
		v[pos]=-1;
	}
	up(i,2,m,1){
		maxx[i]&=maxx[i-1];
	}
	cout<<maxx[m];
	return 0;
}
