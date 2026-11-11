#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],s[N];
bool check(int mid){
	long long minn=1e18+1;
	for(int i=mid;i<=n;i++){
		minn=min(minn,a[i]*mid-(s[i]-s[i-mid]));
	}
//	cout<<minn<<endl;
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<s[i]<<" ";
//	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
//		cout<<mid<<" ";
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
