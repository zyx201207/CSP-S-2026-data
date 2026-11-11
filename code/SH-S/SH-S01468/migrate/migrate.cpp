#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
long long c,t;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans = 1;
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[j]-a[i]>=d && j-i>=2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
