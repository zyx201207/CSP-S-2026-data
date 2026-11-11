#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int a[N];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d&&a[j]-a[i]<2*d&&j-i==3){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}