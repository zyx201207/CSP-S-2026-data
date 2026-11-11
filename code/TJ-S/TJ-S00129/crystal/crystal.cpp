#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define endl "\n"
int n,m;
int a[500009]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=abs(a[2]-a[1]);
	cout<<1+m/p;
	
	return 0;
}
