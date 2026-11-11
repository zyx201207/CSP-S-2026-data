#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,ans,c[514514];
int s[514514];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(c[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
			else l=mid+1;
		}
//		cout<<l<<" ";
		ans=max(ans,i-l+1); 
	}
	cout<<ans;
	return 0;
}
