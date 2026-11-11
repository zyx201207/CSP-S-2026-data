#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	int l=1,r=n;
	while(l<r){
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(c[l]!=c[r]){
			int man=min(a[l],a[r]);
			ans+=man;
			a[l]-=man;
			a[r]-=man;
		}else{
			int man=min(a[l],a[r]);
			a[l]-=man;
			a[r]-=man;
		}
	}
	cout<<ans;
	return 0;
}
