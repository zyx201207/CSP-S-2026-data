#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int sum[N];
int read(){
	int x=0,f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum[i]=(i-1)*(a[i]-a[i-1])+sum[i-1];
	}
	int ans=1;
	if(a[2]-a[1]<=m){
		ans=2;
	}
	for(int i=3;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum[i]-sum[mid]-(a[i]-a[mid])*(mid-1)<=m){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
