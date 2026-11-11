#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=5e5+5;
int n,m;
int a[N];
int sum[N];
bool check(int mid){
	int minn=LONG_LONG_MAX;
	for(int i=mid;i<=n;i++){
		minn=min(minn,a[i]*mid-(sum[i]-sum[i-mid]));
	}
	return minn<=m;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	system("fc crystal.out crystal5.ans");
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

/*
很明显观察到第一题的水晶颗数具备单调性

我们可以先二分一个颗数

先对所有a数组排个序

然后做一个前缀和

对于[i,i+mid-1]需要加的次数应该为它们应到的总和a[i+mid-1]*mid减去当前总和sum[i+mid-1]-sum[i-1]

统计一个min即可

最后return minn<=m

复杂度O(nlogn) 
100pts
*/
