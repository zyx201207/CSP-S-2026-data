#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,d;
int a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=1;i<=n-2;i++){
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d){
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
