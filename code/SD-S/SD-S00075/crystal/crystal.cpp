#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=1,r=n;
	long long sum=0;
	for(int l=n-1;l>=1;l--){
		sum+=a[r]-a[l];
		while(sum>m&&r>l){
			sum-=(a[r]-a[r-1])*(r-l);
			r--;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
