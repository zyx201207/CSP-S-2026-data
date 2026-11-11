#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[500005],s[500005];
bool check(int x,int y){
	if(a[x]>a[y]) return 0;
	int sum=0;
	sum=a[y]*(y-x)-s[y-1]+s[x-1];
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx=-1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		//cout<<i<<"\n";
		int l=1,r=i,mid,ans;
		while(l<=r){
			mid=l+(r-l)/2;
			if(check(mid,i)){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		int cnt=0,j;
		for(j=i;j<=n;j++){
			if(a[j]==a[i]){
				cnt++;
			}else{
				break;
			}
		}
		//cout<<"cnt:"<<cnt<<"\n";
		//cout<<ans<<"\n";
		mx=max(mx,i-ans+cnt);
	}
	cout<<mx;
	return 0;
}// 15:29 完蛋了 