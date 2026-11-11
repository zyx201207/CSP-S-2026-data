#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m,ans=1,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1])flag=0;
	}
	if(flag){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	LL l=1,r=n;
	while(l<=r){
		LL mid=l+(r-l)/2,sum=0,i=1;	
		for( ;i<mid;i++){
			sum+=a[mid]-a[i];
			if(sum<=m)ans=max(ans,i+1);
		}
		if(i==mid)l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
