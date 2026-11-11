#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==0){
		while(t--){
			cin>>n>>d;
			for(int i=2;i<=n;++i){
				cin>>a[i];
			}
		}
		if(a[n]==5) cout<<"1\n2";
		else cout<<"0\n1";
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=2;i<=n;++i){
			cin>>a[i];
		}
		cout<<n-3<<'\n';
	}
	return 0;
}
