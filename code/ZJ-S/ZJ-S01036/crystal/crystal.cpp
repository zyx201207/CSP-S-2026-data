#include<bits/stdc++.h>
using namespace std;
long long n,m,num[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+num[i];
	}
	int l=1,r=n+1,mid;
	while(l<r){
		long long mn=INT_MAX;
		mid=(l+r+1)/2;
		for(int i=1;i<=n-mid+1;i++){
			mn=min(mn,num[i+mid-1]*mid-(sum[i+mid-1]-sum[i-1]));
		}
		if(mn<=m) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}