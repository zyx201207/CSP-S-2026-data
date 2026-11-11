#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[5005],ans;bool yes=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=2500&&a[i]>=-2500){
			b[a[i]+2501]++;
		}
		else{
			yes=0;
		}
	}
	if(yes){
		for(int i=1;i<=5001;i++){
			if(b[i]==0){
				continue;
			}
			long long sum=0,nans=b[i];
			for(int j=i-1;j>=1;j--){
				if(sum+(i-j)*b[j]<=m){
					sum+=(i-j)*b[j];
					nans+=b[j];
				}
				else{
					nans+=(m-sum)/(i-j);
					break;
				}
			}
			ans=max(ans,nans);
		}
	}
	else{
		long long p=max(a[1]-a[2],a[2]-a[1]),sum=0;
		for(int i=1;i<=n;i++){
			sum+=p*i;
			if(sum>m||sum<0){
				break;
			}
			ans++;
		}
	}
	cout<<ans;
	return 0;
}