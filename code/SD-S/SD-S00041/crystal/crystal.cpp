#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define DEBUG_CODE 0
#define NDB if(!DEBUG_CODE)
#define DB if(DEBUG_CODE)
using namespace std;
const int N=2e6+10;
const ll mod=1e9+7;
ll n,m,x,y,z,sum[N],ans,cnt,pans,psum,tot,k,T,u,v,w,l,r,opt,a[N];
int main(){
	NDB{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=1,r=i;
		pans=0;
		while(l<=r){
			int mid=(l+r)>>1;
//			if(i==6) cout<<l<<" "<<r<<" "<<mid<<" "<<((i-mid)*a[i])<<" "<<sum[i-1]-sum[mid-1]<<"\n"; 
			if(((i-mid)*a[i]-sum[i-1]+sum[mid-1])<=m) r=mid-1,pans=i-mid+1;
			else l=mid+1;
		}
		ans=max(ans,pans);
//		if(pans==6) cout<<"!"<<i<<"!";
	}
	cout<<ans;
	return 0;
}
/*
10 13
9 10 10 -4 7 1 0 -6 3 -1 
*/ 
