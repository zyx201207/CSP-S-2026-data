#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[50005];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(1+a,a+1+n); 
	long long ans=0;
	for(long long i=n;i>=1;i--){
		for(long long j=1;j<=i;j++){
			ans=ans+(a[i]-a[j]);
		}
		if(ans<=m){
			cout<<i;
			return 0;
		}else{
			ans=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
