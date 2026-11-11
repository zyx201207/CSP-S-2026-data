#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long ret=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret*f;
}
const int maxn=2000005;
int c,t,n,f[maxn],q[maxn],tal,hed,g[maxn];
long long a[maxn],d;
int find(int x){
	int L=hed,R=tal,cnt=hed;
	while(L<=R){
		int mid=(R+L)/2;
		if(f[mid]>x) R=mid-1;
		else cnt=mid,L=mid+1;
	}
	if(cnt==hed) return 1;
	else if(cnt==tal) return cnt-hed+1;
	return cnt-hed;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();int T=t;
	while(t--){	
		for(int i=1;i<=n;i++) a[i]=read();
		int ans=0;
		for(int st=1;st<=n;st++){
		memset(f,63,sizeof f);memset(g,0,sizeof g);
		f[st]=0;g[st]=1;tal=1,hed=1,q[1]=st;memset(q,0,sizeof q);
		for(int i=st+1;i<=n;i++){
			while(hed<=tal&&abs(a[i]-a[q[hed]])>d) hed++;
			f[i]=f[q[hed]]+1;
			g[i]=find(f[q[hed]]);
			if(g[i]==2) ans++;
			while(hed<=tal&&f[i]<f[q[tal]]) tal--;
			q[++tal]=i;
		}
		printf("%d\n",ans);
	}
	}
	return 0;
}