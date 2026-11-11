#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,a[500005];
	long long m,s,j;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=0,r=n-1,u,ans;
	while(l<=r){
		bool b=true;
		u=(l+r+1)/2;
		s=0;
		for(int i=0;i<u;i++){
			if(s>m-a[i]){
				b=false;
				break;
			}
			s+=a[u]-a[i];
		}
		if(b){
			ans=u;
			l=u+1;
		}
		else r=u-1;
	}
	cout<<ans+1;
	return 0;
}
