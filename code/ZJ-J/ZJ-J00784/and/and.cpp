#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
ll a[2000100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		//cout<<a[i];
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}