#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cpp{
	ll m;
	char s;
}a[200005];
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i].m>>a[i].s;
	for(ll l=1,r=n;l<=r;)
	{
//		cout<<l<<" "<<r<<"\n";
		if(a[l].s==a[r].s){
			if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				a[r].m=0;
				r--;
			}
			else if(a[l].m<a[r].m){
				a[r].m-=a[l].m;
				a[l].m=0;
				l++;
			}
			else{
				a[r].m=a[l].m=0;
				l++,r--;
			}
		}
		else{
//			cout<<"change\n";
			if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				ans+=a[r].m;
				a[r].m=0;
				r--;
			}
			else if(a[l].m<a[r].m){
				a[r].m-=a[l].m;
				ans+=a[l].m;
				a[l].m=0;
				l++;
			}
			else{
				ans+=a[l].m;
				a[r].m=a[l].m=0;
				l++,r--;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

