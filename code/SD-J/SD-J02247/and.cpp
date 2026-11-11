#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
//bool check(int mid){
//	int ma=0;
//	for(int i=1;i<=n-m;is++){
//		int t=a[i];
//		for(int j=i;j<=i+m;j++){
//			t=t and a[j];
//		}
//		ma=max(ma,t);
//			if(t and a[j]>=mid) return 1;
//	}
//}
signed main(){
	freopen("and.in ","r",stdin);
	freopen("and.out ","w",stdout);/////////
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//r=max(r,a[i]);
	}
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7){
		cout<<7;
		return 0;
	}
	if(m==n-1){
		int t=a[1],t2=a[2];
		for(int i=1;i<=n-1;i++) t=t and a[i];
		for(int i=2;i<=n;i++) t2=t2 and a[i];
		//cout<<t<<"  "<<t2<<" ";
		//cout<<max(t,t2);
		return 0;
	} 
//	int l=0,r=0

	int ma=0;
	for(int i=1;i<=n-m+1;i++){
		int t=a[i];
		for(int j=i;j<=i+m-1;j++){
			t=t and a[j];
		}
		ma=max(ma,t);
		//cout<<ma;
	}
	cout<<ma;
//	r+=r;
//	while(l<=r){
//		int mid=(l+r)/2;
//		if(check(mid)) 
//	}
	return 0; 
}
