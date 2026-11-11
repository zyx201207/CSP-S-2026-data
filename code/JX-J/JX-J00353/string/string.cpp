#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long no[200005],n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>no[i]>>a[i];
	long long l=1,r=n,ans=0;
	while(l<r){
		if(no[l]<no[r]){
			long long sum=no[l];
			for(;sum<=no[r];l++){
				if(a[l]!=a[r]) ans+=no[l];
				sum+=no[l+1];
			}
			if(sum-no[l]<no[r]){
				no[l]-=no[r]-sum+no[l];
				if(a[l]!=a[r]) ans+=no[r]-sum+no[l];
			}
		}else {
			long long sum=no[r];
			for(;sum<=no[l];r--){
				if(a[l]!=a[r]) ans+=no[r];
				sum+=no[r-1];
			}
			if(sum-no[r]<no[l]){
				no[r]-=no[l]-sum+no[r];
				if(a[r]!=a[l]) ans+=no[l]-sum+no[r];
			}
		}
		
	}
	cout<<ans;
	return 0;
}
