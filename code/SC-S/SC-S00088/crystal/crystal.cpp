#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	int sum=0;
	for(int i=1;;i++){
		sum+=(a[i]-a[i-1])*(i-1);
		if(sum>m){
			ans=i-1;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}