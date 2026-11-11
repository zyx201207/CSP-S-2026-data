#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],s[500010];
bool cnt(int a,int b){
	return a>b;
}
int ret=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cnt);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[1]-a[i];
	}
	for(int i=1;i<=n;i++){
		if(ret>=n-i+1) break;
		int l=i,r=n,tmp=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(m-s[mid]+(mid-i+1)*s[i]>=0){
				tmp=mid-i+1;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ret=max(ret,tmp);
	}
	cout<<ret;
	return 0;
}
