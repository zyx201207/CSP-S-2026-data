#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(d>=a[n]-a[1]){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int k=a[i],m=i,cnt=0;
				while(k<=a[j]&&m<=j){
					while(k+d>a[m]) m++;
				}
			}
		}
		cout<<1<<"\n";
	}
	return 0;
}
//Oct31==Dec25?
