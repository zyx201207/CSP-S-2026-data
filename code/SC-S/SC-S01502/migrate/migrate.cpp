#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1000005];
int main(){
	ios::sync_with_stdio();
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			cin>>c[j];
		}
		cout<<!(b%2)<<endl;
	}
	return 0;
}