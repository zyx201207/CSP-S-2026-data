#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5 ;
int a[N],sum[N],n,u,v,len,l=1,r=1,ans=0,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	while(r<=n){
		len=r-l+1;
		u=sum[r]-sum[l-1];
		v=a[r]*len;
		if(v-u>m)l++;
		else{
			ans=max(ans,len);
			r++;
		}
	}
	cout<<ans;
	return 0;
}