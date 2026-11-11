#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2!=0){
		cout<<a[n/2+1];
	}
	else{
		cout<<a[n/2];
	}
	return 0;
}
