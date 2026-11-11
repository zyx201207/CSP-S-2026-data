#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll rd(){
	char ch=getchar();bool f=0;ll ret=0;
	while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0') ret*=10,ret+=ch-'0',ch=getchar();
	return f?-ret:ret;
}
ll a[500005];
ll sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	int ans=-1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1; 
			if(k>=a[i]*(i-mid+1)-(sum[i]-sum[mid-1])) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
