#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int ans,n,m,a[N],s[N];
//查询l~r中每个值与a[r]的差之和
inline bool check(int l,int r){
	return (r-l+1)*a[r]-(s[r]-s[l-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,t=0;
		while(l<=r){
			int mid=(l+r)>>1;
//			cout<<mid<<endl;
			if(check(mid,i)){
				r=mid-1;
				t=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-t+1);
//		cout<<"==="<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*
score 100 pts
time 60 min
difficulty:3
md我瞪了100眼终于会了
枚举右端点，二分左端点这不做完了么
时间复杂度O(nlogn)
md瞪了这么久，气死了/ll
感觉自己糖丸了
waitwait这个check好像是O(n)的
哎呦我去
那没事，这个简单，考虑现在做l~r，那么就是
\sum_{i=l}^r (a[r]-a[i]) = \sum_{i=l}^r a[r] - \sum_{i=l}^r a[i] = (r-l+1)*a[r] - (s[r] - s[l-1])
，前缀和维护即可
做完了。
然后这个s由于是5e5*1e12=1e18刚好不会爆long long。
过大样例了。
*/