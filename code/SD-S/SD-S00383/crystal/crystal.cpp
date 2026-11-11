#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum[500005],a[500005],ans;
inline int read(){
	int sum=0,f=1;
	char x=getchar();
	while(!isdigit(x)){
		if(x=='-')f=-1;
		x=getchar();
	}
	while(isdigit(x)){
		sum=(sum<<1)+(sum<<3)+(x^48);
		x=getchar();
	}
	return f*sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i,now;
		while(l<=r){
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-sum[i]+sum[mid-1]<=m){
				now=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans;
} 
