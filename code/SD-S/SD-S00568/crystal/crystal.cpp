#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans,a[N],s[N];
int calc(int x){
	int lim=m-x*a[x]+s[x-1];
	int l=1,r=x-1,mid;
	int res=x;
	while(l<=r){
		mid=(l+r)>>1;
		if(-mid*a[x]+s[mid-1]<=lim){
			res=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return x-res+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1){
		cout<<"1";
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		ans=max(ans,calc(i));
	cout<<ans;
	return 0;
}
