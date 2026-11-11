#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int c=m,s=0;
		for(int j=i;j<=n;j++){
			int v=a[j+1]-a[j];
			if(c>=v*(s+1)){
				s++;
				c-=v*s;
//				cout<<c<<' '<<s<<' '<<v<<' ';
			}
		}
		ans=max(s,ans);
	}
	cout<<ans;
	return 0;
}
