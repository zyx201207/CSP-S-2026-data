#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[500005];
int main(){
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
	int ans=0;
	long long x=0;
	for(int i=1;i<=n;i++){
		int j=i;
		x=0;
		while(j>0){
			if(a[i]*(i-j+1)-sum[i]+sum[j-1]<=m){
				x=a[i]*(i-j+1)-sum[i]+sum[j-1];
				
				ans=max(ans,i-j+1);
				j--;
				
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}

