#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[N],b[N],a1,b1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		a1+=a[i],b1+=b[i];
	}
	int ans=a1+b1;
	if(ans>=m) cout<<ans/m;
	else cout<<m/ans;
}