#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
void read(int &a){
	a=0;char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
void read(ll &a){
	a=0;char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
namespace SHEEP{
	const int N=2e6+5;
	int n;ll d,x[N];
	ll w1[N],w2[N],pw[N];
	int nt[N];
	void work(){
		read(n);read(d);ll ans=0;
		for(int i=1;i<=n;i++) read(x[i]);
		for(int i=n,j=n;i;i--){
			while(x[j]-x[i]>d) j--;
			nt[i]=j;
		}
		for(int i=n;i;i--){
			int j=nt[i];
			if(i==j){
				w1[i]=w2[i]=pw[i]=0;
				continue;
			}
			if(nt[j]==nt[j-1]){
				w1[i]=w2[i]=0;
				pw[i]=(max(nt[j-1],j)-max(nt[j-2],j));
				if(nt[j-1]!=nt[j-2]) pw[i]+=w1[j];
				w2[i]=pw[i];
			}
			else{
				pw[i]=(max(nt[j-1],j)-max(nt[j-2],j));
				w1[i]=w1[j]+(nt[j]-max(nt[j-1],j));
				w2[i]=w2[j]+pw[i];
				if(nt[j-1]==nt[j]-1) w2[i]-=pw[j];
			}ans+=w2[i];
		}
		printf("%lld\n",ans); 
	}
}

int main(){
//	int _=clock();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1,c;
	read(c);
	read(T);
	while(T--) SHEEP::work();
//	cerr<<clock()-_<<endl;
	return 0;
} 
