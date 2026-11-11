#include<bits/stdc++.h>
using namespace std;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rint register unsigned int
#define rshort register unsigned short
char buf[1<<20],*p1,*p2;
template<typename T> inline void read(T& x){
	x=0;char c=gc();
	while(!isdigit(c))c=gc();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=gc();
	}
}
template<typename T> inline void print(T x){
	if(x>9){
		print(x/10);
	}
	putchar(x%10^48);
}
unsigned int tx,n,m,d,q,w[500005],k,a,b,l,r;
unsigned short num[500005];
struct pl{
	unsigned short d;
	unsigned int v;
}v[500005][20];
unsigned long long f[505][505],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(tx),read(n),read(m),read(d),read(q);
	for(rint i=1;i<=m;i++){
		read(w[i]);
	}
	for(rshort i=1;i<=n;i++){
		read(k);
		while(k--){
			read(a),read(b);
			v[a][++num[a]]=pl{i,b};
		}
	}
	for(rshort i=1;i<=n;i++){
		for(rshort j=1;j<=n;j++){
			f[i][j]=1e15;
		}
		f[i][i]=0;
	}
	for(rint i=1;i<=m;i++){
		for(rshort j=1;j<=num[i];j++){
			pl x=v[i][j];
			for(rshort t=j+1;t<=num[i];t++){
				pl y=v[i][t];
				f[x.d][y.d]=f[y.d][x.d]=min(f[x.d][y.d],1ull*x.v+y.v);
			}
		}
	}
	for(rshort t=1;t<=n;t++){
		for(rshort i=1;i<=n;i++){
			if(f[i][t]==1e15||i==t)continue;
			for(rshort j=i+1;j<=n;j++){
				if(f[t][j]==1e15)continue;
				f[i][j]=f[j][i]=min(f[i][j],f[i][t]+f[t][j]);
			}
		}
	}
	while(q--){
		read(l),read(r);
		ans=1e15;
		for(rshort i=1;i<=num[l];i++){
			pl x=v[l][i];
			for(rshort j=1;j<=num[r];j++){
				pl y=v[r][j];
				ans=min(ans,f[x.d][y.d]+x.v+y.v);
			}
		}
		ans+=w[l]+w[r];
		print(ans);
		putchar('\n');
	}
	return 0;
}