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
	const int N=5e5+5;
	int n;ll m,a[N];
	void work(){
		read(n);read(m);
		for(int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+n+1);int ans=1;
		for(int i=1,j=1;j<n;){
			if(j==n) break;
			m-=(j-i+1)*(a[j+1]-a[j]);
			j++;
			while(m<0) m+=a[j]-a[i++];
			ans=max(ans,j-i+1);
		}printf("%d\n",ans);
	}
}

int main(){
//	int _=clock();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	read(T);
	while(T--) SHEEP::work();
//	cerr<<clock()-_<<endl;
	return 0;
} 
