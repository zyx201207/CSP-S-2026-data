#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,m,n,d,a[N],t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>m;
	while(m--){
		t=0;
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>a[i];
		int x=a[1]-a[0];
		int s=d/x;
		if(s<2){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<n-s-1;i++)
			for(int j=i+s+1;j<n;j++){
				if((a[j]-a[i])%d!=0)t++;
			}
		cout<<t<<"\n";
	}
	return 0;
}
