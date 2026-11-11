#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=n-1,r=n,d=a[n]-a[n-1];
	while(l>=1){
		if(d<=m){
			ans=max(ans,r-l+1);
			l--;
			d+=a[r]-a[l];
		} 
		else{
			d-=(r-l)*(a[r]-a[r-1]);
			r--;
		}
	}
	cout<<ans;
	return 0;
}