#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
int n,m;
int a[N];
signed main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=31;i>=0;i--){
		int num=0;
		ans=ans+(1ll<<i);
		for(int j=1;j<=n;j++)
			if((a[j]&ans)==ans) num++;
		if(num<m) ans=ans-(1ll<<i);
	}
	cout<<ans;
	return 0;
}