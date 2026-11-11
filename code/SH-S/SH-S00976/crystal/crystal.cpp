#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,sum[500005];
int n,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(((j-i)*a[j]-(sum[j-1]-sum[i-1]))>m){
				ans=max(ans,j-i);
				i=j-1;
				break;
			}
		}
	}
	if(ans==0) cout<<n;
	else cout<<ans;
	return 0;
}
