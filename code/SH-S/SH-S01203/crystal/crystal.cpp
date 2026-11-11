#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000010];
long long aa[1000010];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	aa[1]=0;
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		aa[i]=(a[i]-a[i-1])*(i-1)+aa[i-1];
	}
	for(long long i=2;i<=n;i++){
		if(aa[i-1]<=m&&aa[i]>m){
			ans=i-1;
		}
	}
	cout<<ans;
	return 0; 
}
