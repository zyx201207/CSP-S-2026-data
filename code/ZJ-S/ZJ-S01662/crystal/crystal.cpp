#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m;
int a[N];
int temp[N];
bool check(int mid){
	int minn=1e9;
	for(int i=mid;i<=n;i++){
		int sum=mid*a[i];
		int cnt=temp[i]-temp[i-mid];
		minn=min(minn,sum-cnt);
	}
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		temp[i]=a[i];
		temp[i]+=temp[i-1];
	}
	int l=0;
	int r=n+10;
	int ans=-1;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid;
	}
	cout<<ans;
	return 0;
}
