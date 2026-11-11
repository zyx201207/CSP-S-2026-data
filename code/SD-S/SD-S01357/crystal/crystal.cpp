#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN=1e6+10;
ll n,m,a[maxN],res,s[maxN],l,r,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])>m) l=mid+1;
			else ans=mid,r=mid-1;
		}
		res=max(res,i-ans+1);
	}
	cout<<res;
	return 0;
} 
