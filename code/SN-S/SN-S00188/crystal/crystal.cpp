#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m;
ll a[N];
ll sum[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	ll l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll now=0,j=1;
	ll ans=-1;
	for(int i=2;i<=n;i++){			
		now+=(a[i]-a[i-1])*(i-j);
		while(now>m&&j<=i){
			now-=(a[i]-a[j]);
			j++;
		}
		if(i-j+1>ans){
			ans=i-j+1;
		}			
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
