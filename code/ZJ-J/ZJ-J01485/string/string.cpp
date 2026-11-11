#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,ans,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<j){
		if(c[i]==c[j]){
			int t=min(a[i],a[j]);
			a[i]-=t;a[j]-=t;
			if(a[i]==0)i++;if(a[j]==0)j--;
		}
		else{
			int t=min(a[i],a[j]);
			a[i]-=t;a[j]-=t;
			if(a[i]==0)i++;if(a[j]==0)j--;
			ans+=t;
		}
	}
	cout<<ans<<"\n";
	return 0;
}