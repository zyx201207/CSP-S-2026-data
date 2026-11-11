#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n, m;
int a[N], sum[N];
int mid, ans;
int find(int k){
	int l=1,r=k-1; 
	while(l<r){
		mid=l+r>>1;
		//cout<<(k-mid)*a[k]-sum[k-1]+sum[mid-1]<<" "<<l<<" "<<r<<"* ";
		int o=(k-mid)*a[k]-sum[k-1]+sum[mid-1];
		if(o<=m) r=mid;
		else if(o>m)l=mid+1;
	}
	//cout<<"\n";
	return l;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int x=0,nans=0;
		int id=find(i);
//		cout<<id<<" ";
		ans=max(ans,i-id+1);
//		for(int j=i;j;j--){
//			int o=(i-j)*a[i]-sum[i-1]+sum[j-1];
//			if(o>m) break;
//			cout<<o<<" ";
//			nans++;
//		}
//		cout<<"\n";
		ans=max(ans,nans);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/