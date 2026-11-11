#include <algorithm>
#include <iostream>
using namespace std;
using LL=long long;
const int N=5e5+10;

LL n,m,a[N];
LL sum,ans=-1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int l=1,r=1;r<=n;r++){
		sum=sum+(a[r]-a[r-1])*(r-l);
		if(sum>m){
			while(sum>m && l<r){
				sum-=(a[r]-a[l]);
				l++;
			}
		}
		else{
			ans=max(ans,(LL)r-l+1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
