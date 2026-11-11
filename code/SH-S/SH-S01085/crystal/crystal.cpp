#include<bits/stdc++.h>
using namespace std;
long long n,ans=1,m,a[500009],b[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	for(long long i=1;i<=n;i++){
		long long sum=0;
		for(int j=i;j<=n-1;j++){
			long long pri=0;
			sum+=b[j]*(j-i+1)+pri;
			pri=sum;
			if(sum<=m){
				ans=max(ans,j+1-i+1);
			}
			else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
