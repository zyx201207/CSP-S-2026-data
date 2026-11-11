#include<bits\stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+9;
int n;
ll m,z[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>z[i];
	sort(z+1,z+n+1);
//	for(int i=1;i<=n;i++)cout<<z[i]<<" ";
//	cout<<"\n";
	ll nm=m;ll sum=1,ans=0;
	for(int l=1,r=1;r<=n;l++,nm+=z[r]-z[l],sum--){
		if(l>r)nm=m,r=l,sum=1;
		if(r>n)break;
		while(nm>=(z[r+1]-z[r])*sum&&r<n)nm-=(z[r+1]-z[r])*sum,r++,sum++;
		ans=max(ans,sum);
//		cout<<ans<<" "<<nm<<" "<<l<<" "<<r<<"\n";
	}
	cout<<ans;
}
