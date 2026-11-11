#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int sum[500005];
bool check(int x,int k){
	int sm=(k-x)*a[k];
	int sm2=sum[k-1]-sum[x-1];
	int nd=sm-sm2;
	return nd<=m;
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int ans=1e18;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
	return 0;
}