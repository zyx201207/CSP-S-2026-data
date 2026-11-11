#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+517;
int n;
ll m;
ll a[N];
ll ans1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1;
	ll sumk=0;
	for(ll r=2;r<=n;r++)
	{	
		if(a[r]>a[r-1]){
			sumk+=(r-l)*(a[r]-a[r-1]);
		}
		while(sumk>m){
			ll nowans=r-l;
			ans1=max(nowans,ans1);
			sumk-=a[r]-a[l];
			l++;
		}

	}
	ans1=max(ans1,n-l+1);
	cout<<ans1;
	
	return 0;
}


/*

14:58  

I'm sory (T^T)

*/
