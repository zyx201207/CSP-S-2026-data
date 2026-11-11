#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int diff[500005],need[500005],sumdiff[500005];
bool check(int mid){
	for(int i=1;i+mid-1<=n;i++){
		if(need[i+mid-1]-need[i]-(i-1)*(sumdiff[i+mid-1]-sumdiff[i])<=m)
			return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		diff[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)
		need[i]=need[i-1]+diff[i]*(i-1);
	for(int i=1;i<=n;i++)
		sumdiff[i]=sumdiff[i-1]+diff[i];
	/*for(int i=1;i<=n;i++)
		cout<<diff[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<need[i]<<" ";
	cout<<endl;*/
	int ans=1;
	int le=1,ri=n;
	while(le<=ri){
		int mid=(le+ri)>>1;
		if(check(mid)){
			ans=mid;
			le=mid+1;
		}
		else ri=mid-1;
	}
	cout<<ans;
	return 0;
}
