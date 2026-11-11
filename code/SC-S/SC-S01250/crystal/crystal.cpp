#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=5e5+30;

int a[N];
int diff[N];
int sum[N];
int n,m;

int Abs(int t){
	return ((t>=0)?t:-t);
}

bool check(int tmp){
	int mn=0;
	for(int i=1;i<=tmp-1;i++){
		mn+=diff[i]*i;
	}
//	cout<<mn<<'\n';
	int lst=mn;
	for(int i=tmp+1;i<=n;i++){
		int now=lst-(sum[i-2]-sum[i-tmp-1])+diff[i-1]*(tmp-1);
		mn=min(mn,now);
		lst=now;
//		cout<<now<<'\n';
	}
	return mn<=m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		diff[i-1]=Abs(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+diff[i];
	}
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<l-1<<'\n';
	return 0;
}//我是florr苦命人、thoita滚木 BOBBY_21 关注洛谷yizibi 