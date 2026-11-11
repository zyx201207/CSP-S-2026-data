#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m;
int a[MAXN];
int suf[MAXN];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]+a[i];
	} 
	int l=n,r=n;
	while(r>0){  
		int k=a[r]*(r-l+1)-suf[l]+suf[r+1];
		ans=max(ans,r-l);
		if(m>=k && l>0){
			l--;
		}else{
			r--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//Oct31==Dec25?
