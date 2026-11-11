#include<bits/stdc++.h>
using namespace std;
long long a[2000005],d;
int c,t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]>d){
				n=i-1;
				break;
			}
		}
		int best=a[1]+d+d-1;
		if(a[n]<best) cout<<0<<endl;
		else{
			for(int i=n;i>=1;i--){
				if(a[i]<best){
					cout<<n-i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}