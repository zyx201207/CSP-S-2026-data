#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid (l+r)/2
inline int read(){
	int x=0,f=1;
	char g=getchar();
	while(g<'0'||g>'9'){
		if(g=='-')f=-1;
		g=getchar();
	}
	while(g>='0'&&g<='9'){
		x=x*10+g-'0';
		g=getchar();
	}
	return x*f;
}
int n,m,a[500005],sum[500005];
bool check(int x){
	for(int i=x;i<=n;i++){
		int ch=a[i]*(x-1)-(sum[i-1]-sum[i-x-1]);
		if(ch<=m)return true;
	}
	return false;
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
		sum[i]=a[i]+sum[i-1]; 
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

