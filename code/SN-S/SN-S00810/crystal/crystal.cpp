#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum,k,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			sum+=abs(a[i]-a[j]);
			if(sum<=m){
				k++;
			}
			else{
				ans=max(ans,k);
				break;
			}
		} 
		ans=max(ans,k);
		sum=0;
		k=0;
	}
	cout<<ans;
	return 0;
	
	
} 
