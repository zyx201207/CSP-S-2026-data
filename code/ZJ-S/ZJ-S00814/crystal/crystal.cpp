#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],tot,ans;
bool cmp(int u,int v){
	return u<v;
}
bool check(int t){
	int res=0;
	for(int i=t;i>=1;i--){
		res+=a[t]-a[i];
		if(res>m){
			ans=max(ans,t-i);
			return 0;
		}
	}
	ans=max(ans,t);
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int la=n;b[n]=n;
	for(int i=n-1;i>=1;i--){
		if(a[i]==a[i+1])b[i]=b[i+1];
		else b[i]=i;
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(b[mid]))l=mid+1;
		else r=mid-1;
	}
	while(a[ans+1]==a[ans])ans++;
	cout<<ans;
	return 0;
}