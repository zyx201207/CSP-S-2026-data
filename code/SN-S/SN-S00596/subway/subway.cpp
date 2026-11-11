#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q,ans,mx=-1,a[N][N],w[N],k[N],t[N][N],x[N],y[N];
inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return ans*f;
} 
long long solve(long long x,long long y){
	if(mx<=2){ 
		ans+=w[x]+w[y];
		for(int i=x;i<=y;i++){
			ans+=t[1][i];
		}
		return ans; 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read(); 
	}
	for(int i=1;i<=n;i++){
		k[i]=read(); 
		mx=max(mx,k[i]);
		for(int j=1;i<=k[i];i++){
			a[i][j]=read(),t[i][j]=read(); 
		}
	}
	for(int i=1;i<=q;i++){
		x[i]=read(),y[i]=read();
		solve(x[i],y[i]);
		cout<<ans;
	} 
	return 0;
}
