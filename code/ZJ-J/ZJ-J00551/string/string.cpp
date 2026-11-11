#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,i,l,r,res;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	l=1;r=n;
	while(l<r){
		res+=(c[l]!=c[r])*min(a[l],a[r]);
		if(a[l]==a[r]) l++,r--;
		else if(a[l]>a[r]) a[l]-=a[r--];
		else a[r]-=a[l++]; 
	}
	cout<<res;
	return 0;
}
