#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
int n,m,a[maxn],b[maxn],ans=LLONG_MIN,Ta,Tb,Tt;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==i)Ta++;
		if(abs(a[i])<=100)Tt++;
	}
	if(Ta==n){
		for(int i=1;i<=n;i++){
			if(i*(i-1)/2>m){printf("%lld\n",i-1);return 0;}
		}
		printf("%lld\n",n);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]==a[i+1]-a[i])Tb++;
	}
	if(Tb==n-2){
		int k=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(k*i*(i-1)/2>m){printf("%lld\n",i);return 0;}
		}
		printf("%lld\n",n);
		return 0;
	}
	if(Tt==n){
		for(int i=1;i<=n;i++){
			int p=a[n]*(n-i)-b[n-1];
			if(p<=m){printf("%lld\n",n-i+1);break;}
		}
	}
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
//One
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int p=a[j]*(j-i)-b[j-1];
			if(p>m)continue;
			ans=max(ans,j-i+1);
		}
	}
//Two
//	for(int i=1;i<=n;i++)v[i]=v[i-1]+(a[i]-a[i-1])*(i-1);
//	for(int i=1;i<=n;i++)c[i]=v[i]-a[i];
//	for(int i=1;i<=n;i++){
//		int x=m-b[i-1];
//		int pos=lower_bound(c+1,c+1+n,x)-c-1;
//		ans=max(ans,i-pos+1);
//	}
	printf("%lld\n",ans);
	return 0;
}
