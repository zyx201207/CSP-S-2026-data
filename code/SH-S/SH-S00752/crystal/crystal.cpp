#include<bits/stdc++.h>
using namespace std;
#define N 555555
#define int long long
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int n,m,a[N],s[N],ans;
signed main(){
	open("crystal");
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=0;i--)s[i]=s[i+1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(s[i]-s[mid]+(i-mid)*a[i]<=m)r=mid-1;
			else l=mid+1;
		}
		if((i-l)*a[i]+s[i]-s[l]<=m)ans=max(ans,i-l+1);
		if(r&&(i-r)*a[i]+s[i]-s[r]<=m)ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
}