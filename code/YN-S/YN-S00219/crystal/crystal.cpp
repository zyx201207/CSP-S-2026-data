#include<bits/stdc++.h>
using namespace std;

#define int long long
using P =pair<int,int>;
const int N=5e5+5;

int n,m;
int a[N];
int s[N];
int mn=INT_MAX;
int work(int i,int num){
	int l=1,r=i;
	int re_=i;
	while(l<=r){
		int mid=(l+r)>>1;
		if(num*(i-mid+1)-s[i]+s[mid-1]<=m){
			re_=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return re_;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mn=min(mn,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]-=mn;
	}
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	int ans =1ll;
	for(int i=1;i<=n;i++){
//		cout<<i<<" "<<work(i,a[i])<<endl;
		ans=max(ans,i-work(i,a[i])+1ll);
	}
	cout<<ans<<endl;
}

int t_;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	t_=1;
//	cin>>t_;
	
	while(t_--){
		solve();
	}
	
//	cout.flush();
	
	return 0;
}
