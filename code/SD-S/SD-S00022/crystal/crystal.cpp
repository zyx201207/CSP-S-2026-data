#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=500005;
int n;
ll a[N],m,ans=0;

void solve(){
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		ll cnt=0,res=0;
		for(int j=i-1;j>=1;j--){
			ll w=a[i]-a[j];
			if(w>m||res+w>m) break;
			res+=w;
			cnt++;
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	solve();
	
	return 0;
}
