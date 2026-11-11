#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,ans,cnt,a[maxn],b[maxn];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		b[i-1]=a[i]-a[i-1];
	}
	int num=0;
	for(int l=1,r=0;r<=n-1;){
		if(num<=m){
			r++;
			num+=b[r]*(r-l+1);
			cnt++;
			if(num>m){
				continue;
			}else{
				ans=max(cnt,ans);
			}
		}else{
			num-=(a[r+1]-a[l]);
			l++;
			cnt--;
		}
	}
	cout<<ans+1;
	return 0;
}