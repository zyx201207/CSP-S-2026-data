#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,ans;
long long m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1,j=1;j<=n&&i<=j;i++){
		while((j-i+1)*a[j]-sum[j]+sum[i-1]<=m&&j<=n){
			ans=max(ans,j-i+1);
			j++;
		}
	}
	cout<<ans;
	return 0;
} 
