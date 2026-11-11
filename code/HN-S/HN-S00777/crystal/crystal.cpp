#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m;
int a[N],s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
//		cout<<a[i]<<" ";
	}
//	cout<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
//		cout<<r<<" "<<i<<"\n";
	}
	cout<<ans;
	return 0;
}
/*
三年了，会赢的 
*/ 

