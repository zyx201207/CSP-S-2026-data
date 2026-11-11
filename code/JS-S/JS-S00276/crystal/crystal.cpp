#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define ins insert
#define int long long
#define pii pair<long long,long long>
#define endl "\n"
int n,m,a[500012],sum[500012],ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i-1,mid,val,curAns=-1;
		while(l<=r){
			mid=l+(r-l)/2;
			val=(i-mid)*a[i];
			val=val-sum[i-1]+sum[mid-1];
			//cout<<i<<" "<<mid<<" "<<val<<endl;
			if(val<=m){
				curAns=i-mid+1;r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,curAns);
	}
	cout<<ans;
}
//diff -Z -B
