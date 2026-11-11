//马知遥 西安交通大学附属中学 SN-S00380  
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],pre[1000005];
int n,m;
bool check(int x){
	int sum,sum2=1e18;
	for(int i=x;i<=n;i++){
		sum=a[i]*x;
		sum-=pre[i]-pre[i-x];
		sum=abs(sum);
		sum2=min(sum,sum2);
	}
	return (sum2<=m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
}
