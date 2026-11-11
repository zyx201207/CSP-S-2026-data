#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],maxx=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans;
		while(l<=r){
			int mid=(l+r+1)/2;
			if(s[i-1]-s[mid-1]+m<(i-mid)*a[i]){
				l=mid+1;
			}
			else{
				ans=mid;
				r=mid-1;
			}
		}
		if(ans<i) maxx=max(maxx,i-ans+1);
	}
	cout<<maxx;
	return 0;
}
