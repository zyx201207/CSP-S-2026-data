#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
		if(sum[i]==m){
			cout<<i;
			return 0;
		}
	}
	if(m>sum[n]){
		cout<<n;
		return 0;
	}
	int l=1,r=n,mid,cnt=0;
	while(l<r){
		cnt++;
		if(cnt>=50){
			mid=(l+r)/2;
			break;
		}
		mid=(l+r)/2;
		if(sum[mid]==m){
			break;
		}
		if(sum[mid]<m){
			l=mid;
		}
		else{
			r=mid;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i];
//	}
	cout<<mid;
}
