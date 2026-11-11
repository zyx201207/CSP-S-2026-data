#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int cf[N],s[N];
//int dp[N];
int ans;
int l,r;
int cnt;
int t;
//bool check(int x){
//	int st=a[x],res=0;
//	for(int i=1;i<=x;i++){
//		res+=a[i]-st;
//	}
//	return res<=m;
//}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	//	cout<<++t<<endl;
	//	cf[i]=a[i]-a[i-1];
	//	s[i]=s[i-1]+cf[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
		s[i]=s[i-1]+cf[i];
		if(i==1)s[1]=0,cf[1]=0;
//		cout<<cf[i]<<' '<<s[i]<<endl;
	}
//	cout<<endl<<endl;
	l=1,r=1;
	while(l<=r&&r<=n){
		cnt+=(r-l)*cf[r];
		while(cnt>m){
			cnt-=(s[r]-s[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	//	cout<<l<<' '<<r<<' '<<cnt<<' '<<ans<<endl;
	}
	cout<<ans;
//	r=n;
//	while(l<r){
//		int mid=(l+r+1)/2;
//		if(check(mid))l=mid;
//		else r=mid-1;
//	}
//	cout<<l;
	return 0;
}
/*
21 116
484 857 452 783 125 736 223 85 605 657 677 681 391 206 520 336 727 857 507 748 359
*/
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
