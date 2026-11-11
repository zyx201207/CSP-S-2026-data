#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n,m;
int ans;
int a[500050];
int s[500050];
int get(int l,int r,int x){
	return (r-l+1)*x-(s[r]-s[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(get(mid,i,a[i])>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;	
	return 0;
}

