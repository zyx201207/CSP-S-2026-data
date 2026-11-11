#include <bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(c[l]==c[r]){
			int tmp=min(a[l],a[r]);
			a[l]-=tmp;
			a[r]-=tmp;
		}
		else{
			int tmp=min(a[l],a[r]);
			a[l]-=tmp;
			a[r]-=tmp;
			ans+=tmp;
		}
	}
	cout<<ans;
	return 0;
}
