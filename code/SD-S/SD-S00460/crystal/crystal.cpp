#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,ans=1;
long long a[500010];
bool check(long long mid)
{   long long sum=0,h=1;
	for(int i=mid-1;i>=1;i--)
	{   sum+=a[mid]-a[i];
		h++;
	}
	if(sum<=m){
		ans=max(ans,h);
		return 1;	
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	l=0,r=n+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<ans;
	return 0;
}

