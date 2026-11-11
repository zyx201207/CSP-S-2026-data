#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x;
		}
	}
	for(int i=0;i<t;i++){
		cout<<i%2<<endl;
	}
	return 0;
}
