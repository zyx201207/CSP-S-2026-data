#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
int a[N],f[N],f1[N],f2[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=1;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		f1[i]=f1[i-1]+f[i]*(i-1);
	}
	for(int i=1;i<=n;i++){
		if(f1[i]>m){
			ans=i-1;
			break;
		}
	}
	for(int i=2;i<=n;i++){
		int t=1;
		f2[i]=1;
		for(int j=i+1;j<=n;j++){
			f2[j]=f2[j-1]+f[i]*(j-i);
			if(f2[j]>m){
				t=j-1;
				if(j==i+1)t=1;
				break;
			}
		}
		ans=max(ans,f2[t]);
	}
	printf("%lld",ans);
	return 0;
} 
