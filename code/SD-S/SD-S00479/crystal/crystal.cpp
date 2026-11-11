#include<bits/stdc++.h>
#define ll long long
#define pr(x) pair<x,x>
#define up(i,j,k,l) for(int i=j;i<=k;i+=l)
#define down(i,j,k,l) for(int i=j;i>=k;i-=l)
using namespace std;
const int N=5e5+10;
int n;
ll m;
ll a[N],q[N];
bool check(int l,int r,ll x)
{
	return 1ll*x*(r-l+1)-(q[r]-q[l-1])<=m;
}
int ans;
void solve()
{
	cin>>n>>m;
	up(i,1,n,1){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	up(i,1,n,1){
		q[i]=q[i-1]+a[i];
	}
	int l,r,mid,res;
	up(i,1,n,1){
		l=1;
		r=i;
		res=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,i,a[i])){
				res=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		//cout<<"RES"<<i<<' '<<res<<endl;
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
	//cin>>_;
	up(i,1,_,1){
		solve();
	}
	return 0;
} 
