#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5;
long long n,m;
long long a[maxn+1];
long long mid;
long long ans1,ans2,ans;
long long M;
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
srand(time(0));
cin>>n>>m;M=m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
stable_sort(a+1,a+n+1);
//cout<<1<<endl;
for(int l=1,r=1;l<=r&&l<=n&&r<=n;r++){
	sum+=(r-l)*(a[r]-a[r-1]);
//	cout<<l<<" "<<r<<" "<<sum<<endl;
	if(sum<=m){
		ans=max(ans,(long long)(r-l+1));
	}
	else{
		while(l<=r&&sum>m&&l<=n&&r<=n){
		sum-=(a[r]-a[l]);
		l++;
	//	cout<<l<<" "<<r<<" "<<sum<<endl;
		}
	}
}cout<<ans;
return 0;}
