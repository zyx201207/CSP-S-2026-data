#include<bits/stdc++.h>
using namespace std;
#define FILENAME "crystal"

long long n,m,a[500001],ans=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	int l=n,r=n;
	__int128 diff=0;
	while(r>1 && l>1){
		while(l>1 && (diff+a[r]-a[l-1]) <=m)
			diff+=(a[r]-a[l-1]),l--;
		if(r-l+1>ans) ans=r-l+1;
		do{
			r--;
		} while(r>1 && a[r]==a[r+1]);
		diff-=(r-l+1)*(a[r+1]-a[r]);
	}
	cout<<ans;
	return 0;
}