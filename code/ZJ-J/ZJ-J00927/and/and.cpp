#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,a[maxn],f[25][maxn],ans,b[maxn],c[maxn];
int read(){
	int num=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
	return num*f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n<=2000){
		if(n==m){
			ans=a[1];
			for(int i=2;i<=n;i++)ans=ans&a[i];
			cout<<ans;
			return 0;
		}
		if(m==1){
			for(int i=1;i<=n;i++)ans=max(ans,a[i]);
			cout<<ans;
			return 0;
		}
		if(m==2){
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
			cout<<ans;
			return 0;
		}
		if(n<=20){
			int k=(1<<n)-1;
			for(int i=1;i<=k;i++){
				int sum=0,x=i,y=2147483647,z=0;
				while(x){
					z++;
					if(x&1)sum++,y&=a[z];
					x>>=1;
				}
				if(sum!=m)continue;
				ans=max(ans,y);
			}
			cout<<ans;
			return 0;
		}
	}
	if(n==m+1){
		b[1]=a[1];
		c[n]=a[n];
		for(int i=2;i<=n;i++){
			b[i]=b[i-1]&a[i];
		}
		for(int i=n-1;i;i--){
			c[i]=c[i+1]&a[i];
		}
		for(int i=1;i<=n;i++){
			if(i==1)ans=c[2];
			else if(i==n)ans=max(ans,b[n-1]);
			else ans=max(ans,b[i-1]&c[i+1]);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}