#include<bits/stdc++.h>
using namespace std;
const int N=4e6;
long long n,a[N],c,t,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=d/(a[2]-a[1]);
		cout<<n-2*x+1<<"\n";
	}
	return 0;
}
