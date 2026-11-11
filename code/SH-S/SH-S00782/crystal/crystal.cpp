#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+5;
int n;
ll m;
ll a[N],s[N];

inline bool chk(int l,int r,ll c){
	return ((r-l+1)*c-(s[r]-s[l-1]))<=m;
}

int sv(int i){
	int ans=i;
	int l=1,r=i;
	ll c=a[i];
	while(l<=r){
		int mid=(l+r)/2;
		if(chk(mid,i-1,c)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return i-ans+1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	
	int res=0;
	for(int i=1;i<=n;i++)res=max(res,sv(i));
	cout<<res;
	
	cout<<flush;
	return 0;
}
