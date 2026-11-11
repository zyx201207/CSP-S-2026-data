//王浩澜 西安交通大学附属中学 SN-S00516
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],l,r,mid,ans,mx=-1,mxi,mn=-1e18;
bool check(int i,int k){
	return a[i]*(i-k+1)-s[i]+s[k-1]<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		mn=min(mn,a[i]);
	}
//	for(int i=1;i<=n;i++){
//		a[i]-=mn;
//		s[i]=s[i-1]+a[i];
//	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=1,r=i;
		while(l<=r){
			mid=l+r>>1;
			if(check(i,mid)){
				ans=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
//		if(i-ans+1>mx){
//			mxi=i;
//			cout<<i<<" "<<i-ans+1<<" "<<a[i]*(i-ans+1)-s[i]+s[ans-1]<<endl;
//		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
//	cout<<endl<<mxi;
	return 0;
}
