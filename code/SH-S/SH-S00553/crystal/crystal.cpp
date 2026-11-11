#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int maxn=a[1],ans=1,sum=0;
	for(int l=1,r=1;r<=n;){
		maxn=a[r];
		if(sum<=m){
			ans=max(ans,r-l+1);
			sum+=(r-l+1)*(a[r+1]-maxn);
			r++;
		}
		else{
			sum-=maxn-a[l];
			l++;	
		}
	}
	if(ans==1) cout<<0<<endl;
	else cout<<ans;
	return 0;
}
