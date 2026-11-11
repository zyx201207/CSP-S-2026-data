#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;

int c,T,n,d,a[N];

signed main(){
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int x=a[2]-a[1];
		cout<<2*d/x<<endl;
	}
	return 0;
}

