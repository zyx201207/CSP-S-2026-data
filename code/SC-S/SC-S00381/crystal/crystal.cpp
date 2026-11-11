#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5;
ll a[N+2];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	int l=1,r=1,ans=0;
	ll sum=0;
	while(r!=n+1){
		if(sum+(r-l)*(a[r]-a[r-1])<=m){
			sum+=(r-l)*(a[r]-a[r-1]);
			r++;
			ans=max(ans,r-l);
		}
		else{
			sum-=a[r-1]-a[l];
			l++;
		}
		//cout<<l<<" "<<r<<":"<<sum<<"\n";
	}
	cout<<ans;
	return 0;
}
