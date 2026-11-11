#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500100];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int l=1,ans=1,mf=m;;
	for(int i=2;i<=n;i++){
		mf-=(a[i]-a[i-1])*(i-l);
		while(mf<0){
			mf+=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
