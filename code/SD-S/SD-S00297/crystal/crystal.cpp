#include<bits/stdc++.h>
using namespace std;
#define int long long
//100pt (maybe) 
const int N=5e5+5;
int n,m,sum,ans=1,c,f;
int a[N],s[N],b[N],dp[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
//		cout<<"::"<<s[i]<<"\n";
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;//×îÐ¡µÄj 
		while(l<r){
			int mid=l+r>>1;
			if(s[i]-s[mid]-(a[i]-a[mid])*(mid-1)<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

