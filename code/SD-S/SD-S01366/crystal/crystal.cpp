#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+9;
int n,ans;
int m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)s[i]=s[i+1]+a[n]-a[i];
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(s[mid]-s[i]-(a[n]-a[i])*(i-mid)<=m){
				r=mid-1;
				ans=max(ans,i-mid+1);
				
			}else{
				l=mid+1;
			}
		}
	}
//	cout<<s[1]<<" "<<s[4957]<<" ";
	cout<<ans;
	return 0;
}
