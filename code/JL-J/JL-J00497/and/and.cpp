#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		long long int ans=0;
		for(int i=1;i<=n;i++){
			long long int k;
			cin>>k; 
			ans=max(ans,k);
		}
		cout<<ans;
	}
	else if(m==n){
		long long ans;
		cin>>ans;
		for(int i=2;i<=n;i++){
			long long k;
			cin>>k;
			ans&=k;
		} 
		cout<<ans;
	}
	return 0;
}
