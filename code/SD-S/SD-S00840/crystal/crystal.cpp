#include<bits/stdc++.h>
#define int long long

using namespace std;
//using namespace __gnu_pbds;

const int N=5e5+5;
int n,m;
int a[N],s[N];

bool check(int st,int mid){
	return (mid-st+1)*a[mid]-(s[mid]-s[st-1])<=m;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n,mid,res=0;
		while(l<=r){
			mid=l+r>>1;
			if(check(i,mid)){
				l=mid+1;res=mid;
			}else{
				r=mid-1;
			}
		}
//		cout<<res<<"\n";
		ans=max(ans,res-i+1);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}



