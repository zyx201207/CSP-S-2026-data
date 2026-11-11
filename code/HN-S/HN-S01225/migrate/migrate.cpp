#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,t,a[N],n,d;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long x=a[2]-a[1];
		cout<<(x<=d?n*(n-1)/2:0)<<'\n'; 
	}
	return 0;
}
 
