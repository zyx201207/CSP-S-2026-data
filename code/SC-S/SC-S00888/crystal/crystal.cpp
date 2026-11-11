#include<bits/stdc++.h>
#define sjh0626s return
#define code 0
#define ll long long
#define int ll
#define PII pair<int,int>
#define all(v) v.begin(),v.end()
using namespace std;
const int N=5e5+10;
int T=1,n,m,a[N],sm[N],ans,cnt,sum;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1]+a[i];
	}
//	cout<<sm[]
	for(int i=1;i<=n;i++){
		cnt=0,sum=0;
		int L=1,R=i,now=0;
		while(L<=R){
			int mid=(L+R)/2;
			if((i-mid+1)*a[i]-(sm[i]-sm[mid-1])<=m)R=mid-1,now=mid;
			else L=mid+1;
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans;
}
/*
1ms think about O(N^2)
怎么优化
16min:N log N 100 + 0 + 0 + 0
*/
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cin>>T;
	while(T--)solve();
	sjh0626s code;
}