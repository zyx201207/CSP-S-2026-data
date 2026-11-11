#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int sum[N];
int n,m;
bool check(int mid){//mid数量 
	for(int i=1;i+mid-1<=n;i++){
		int l=i,r=i+mid-1;	//i~i+mid-1求和a[i+mid-1]-a[j] 
		//=a[i+mid-1]*mid-(Σi i+mid-1 )
		int s=(a[i+mid-1]*mid)-(sum[i+mid-1]-sum[i-1]);//推出= a[i+mid-1]*mid-sum[i+mid-1]+sum[i-1] 
//		s=0;
//		for(int j=i;j<=i+mid-1;j++){
//			s+=sum[j]-sum[j-1];
//		}
		if(s<=m)return 1;
	}
	return 0;
}
//4 
//0 999 999 999 999 1000
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//二分
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;//二分枚举水晶数量
		if(check(mid))l=mid;
		else r=mid; 
	} 
	cout<<l;
	return 0;
}

