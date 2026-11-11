#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans,w,flag;
long long a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("crystal3.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans+=a[n]-a[i];
	}
	if(ans<=m){
		cout<<n;
		return 0;
	}
	long long l=1,r=n,mid;
	while(l<r){
		sum=0,flag=0;
		mid=(l+r+1)/2;
		for(int i=1;i<=mid;i++){
			sum+=a[mid]-a[i];
		}
		if(sum<=m){
			l=mid;
			continue;
		}
		for(int i=mid+1;i<=n;i++){
			sum-=a[i]-a[i-mid];
			sum+=(a[i]-a[i-1])*mid;
			if(sum<=m){
				l=mid;
				flag=1;
				break;
			}	
		}
		if(flag==0){
			r=mid-1;
		}
	}
	cout<<l;
	return  0;
}

