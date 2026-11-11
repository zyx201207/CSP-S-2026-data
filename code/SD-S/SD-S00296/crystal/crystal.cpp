#include<bits/stdc++.h>
#define f(i,a,b) for(auto i=a;i<=b;i++)
using namespace std;
const int maxn=5e5+10;
long long a[maxn],m,s[maxn];
int n,ans;
int main(){freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;f(i,1,n) cin>>a[i];sort(a+1,a+1+n);
	f(i,1,n) s[i]=s[i-1]+a[i];
	f(i,1,n){
		int l=1,r=i-1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m) r=mid-1;
			else l=mid+1;
		}ans=max(ans,i-r);
	}cout<<ans<<'\n';
	return 0;
}
