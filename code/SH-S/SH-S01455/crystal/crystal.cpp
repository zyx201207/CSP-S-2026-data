#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN];
int pl[MAXN],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pl[i]=pl[i-1]+a[i];
	}
	int j=1;
	for(int i=1;i<=n;i++){		
		while((i-j+1)*a[i]-pl[i]+pl[j-1]>m && j<=i)	j++;
		ans=max(i-j+1,ans);
	}
	cout<<ans<<endl;
}

