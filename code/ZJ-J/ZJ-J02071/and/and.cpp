#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],maxx;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<0;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-2];
	}
	return 0;
}
