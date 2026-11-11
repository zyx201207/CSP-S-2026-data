#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long a[N],f[N];
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		k=(k<<1)+(k<<3)+(ch^48);
		ch=getchar();
	}
	return k*f;
}
int ans,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		f[i]=f[i+1]+a[n]-a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(f[mid]-f[i]-(a[n]-a[i])*(i-mid+1)<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
