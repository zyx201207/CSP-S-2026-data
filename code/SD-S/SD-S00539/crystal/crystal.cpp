#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PII pair<int,int>
const int N=5e5+5,mod=1e9+7;//5e17?
int n,m,q,T;
int a[N];
int sum[N];
inline bool check(int x,int k){
	return sum[k]-sum[x-1]+m>=a[k]*(k-x+1);
}
signed main(){
	ios;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cin>>T;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i,cur=i;//求出最多能同化多少个水晶，二分+前缀和朴素 
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid-1;
				cur=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-cur+1);
	}
	cout<<ans;
	return 0;
}
