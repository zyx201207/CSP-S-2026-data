#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define snd second

using namespace std;
typedef long long ll;

int n,ans;
ll m;
vector<ll> a,sum;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	a.assign(n+1,0);
	sum.assign(n+1,0);
	rep(i,1,n) cin>>a[i];
	
	sort(a.begin()+1,a.end());
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	rep(i,1,n){
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			ll Cost=a[i]*(i-mid)-sum[i-1]+sum[mid-1];
			if(Cost>m) l=mid+1;
			else r=mid; 
		}
		ans=max(ans,i-l+1);
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
