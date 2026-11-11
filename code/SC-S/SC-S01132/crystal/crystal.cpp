#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int man=5e5+10;
ll a[man],ans,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll l=1,r=1,res=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(r<=n){
		while(res<=m&&r<n){
			res+=(a[r+1]-a[r])*(r-l+1);
			ans=max(ans,r-l+1);
			r++;
		}
		if(res<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			res-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}