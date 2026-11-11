#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N];
ll sum,mm=0,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll ar=0;
	sort(a+1,a+1+n);
	ll sr=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i+1]-a[i]==sr){
			ar++;
		}
		else break;
	}
	//cout<<ar<<'\n';
	if(ar==n-2){
		for(int i=1;i<=n;i++){
			if(i*a[i]-(a[1]+a[i])*i/2>m){
				ans=i-1;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=n;i>=1;i--){
			sum=0;
			//ans=0;
			for(int j=1;j<=i;j++){
				sum+=a[i]-a[j];
				if(sum>m) ans=j-1;
			}
			ans=max(ans,mm);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
