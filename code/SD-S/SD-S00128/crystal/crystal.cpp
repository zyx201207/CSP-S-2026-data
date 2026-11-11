#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int read(){
	int res=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
int n,m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,res;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
				r=mid-1;
				res=r;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res);
	}
	cout<<ans<<'\n';
	return 0;
}
