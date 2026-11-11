#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,ans,k;
long long a[N],m,sum[N];
int main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		while(sum[i-1]+(i-k-1)*(a[i]-a[i-1])>m){
			k++;
			sum[i-1]-=a[i-1]-a[k-1];}
		sum[i]=sum[i-1]+(i-k-1)*(a[i]-a[i-1]);
		ans=max(ans,i-k);}
	cout<<ans;
}
