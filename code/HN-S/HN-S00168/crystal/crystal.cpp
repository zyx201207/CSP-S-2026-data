//freopen!!!!!
#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int> 
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],ans; 
bool check(int x,int i){
	int d=i-x;
	int sum=s[i-1]-s[x-1];
	return (d*a[i]-sum<=m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//	cout<<check(3,1);
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,mid;
		while(l<=r){
			int mid=l+r>>1;
	//		if(i==3) cout<<mid<<' '<<l<<' '<<r<<' '<<check(mid,i)<<'\n';
			if(check(mid,i)) r=mid-1;
			else l=mid+1;
		}
	//	cout<<l-1<<" ";//<<' '<<i-(l-1)+1<<'\n';
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5 
1 2 4 8 9
now 14:42
什么叫3个题都跟图有关，ccf神了
T1
容易想到枚举a_i作为目标，那么一定是取i前面连续一段进行加
于是问题转化为，对于i，找一个最大的j，也就是选取i~j 
考虑二分，于是做完了
在14:55通过了大样例。 
*/
