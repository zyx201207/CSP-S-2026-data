#include<iostream>
#include<algorithm>
#define F(i,k,n) for(int i=(k);i<=(n);++i)
#define RF(i,n,k) for(int i=(n);i>=(k);--i)
#define LL long long
using namespace std;
LL a[500005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n;
	LL m;
	cin>>m;
	F(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int p=1;
	LL sum=0;
	int ans=1;
	F(i,2,n){
		sum+=(a[i]-a[i-1])*(i-p);
		while(sum>m&&p<i){
			sum-=a[i]-a[p];
			++p;
		}
		ans=max(i-p+1,ans);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

100pts
*/