#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans[500005];
long long chong[500005];
long long x[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			x[j]=0;
		}
		for(long long j=i;j<=n;j++){
			chong[j]=a[j];
			if(x[chong[j]]!=0){
				for(long long l=x[chong[j]];l<j;l++){
					chong[l]=0;
					x[a[l]]=0;
				}
			}
			x[a[j]]=j;
		}
		for(long long j=i;j<=n;j++){
			ans[chong[j]]++;
		}	
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
