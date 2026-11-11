#include<bits/stdc++.h>
using namespace std;
const int d=2e6;
int c,t,n,m,a[d+5],cha;
bool flag=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>a[1]>>a[2];
		cha=a[2]-a[1];
		for(int i=3;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=cha){
				flag=0;
			}
		}
		if(flag==1){
			int ans=0;
			for(int i=m+1;i<2*m;i++){
				ans+=(n-i);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
