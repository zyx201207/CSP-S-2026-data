#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll INF=1e18;
int n;ll m;
ll a[N];
map <ll,int> mp;
struct A{
	ll val,cnt;
}arr[N];
int z=0;
ll sum[N];
ll sumcnt[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	for (auto now:mp){
		arr[++z]={now.first,now.second};
	}
	for (int i=1;i<=z;i++){
		sum[i]=sum[i-1]+arr[i].val*arr[i].cnt;
		sumcnt[i]=sumcnt[i-1]+arr[i].cnt;
	}
	ll maxcnt=0;
	arr[0].val=-INF;
	for (int i=1;i<=z;i++){
		int l=1,r=i-1,mid,ans=i;
		while(l<=r){
			mid=(l+r)>>1;
			ll cnt=sumcnt[i-1]-sumcnt[mid-1];
			ll nd=arr[i].val*cnt-(sum[i-1]-sum[mid-1]);
			if (nd<=m){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		ll cnt=sumcnt[i-1]-sumcnt[ans-1];
		ll nd=arr[i].val*cnt-(sum[i-1]-sum[ans-1]);
		ll res=m-nd;
		ll mcnt=min(arr[ans-1].cnt,res/(arr[i].val-arr[ans-1].val));
		maxcnt=max(maxcnt,arr[i].cnt+cnt+mcnt);
	}
	cout << maxcnt;
	


	return 0;
}
