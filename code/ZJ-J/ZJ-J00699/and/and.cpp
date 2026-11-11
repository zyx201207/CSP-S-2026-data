#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+5;
ll n,m,a[N],ma;
int main(){
	
	freopen("and.in""r""stdin");
	freopen("and.out""w""stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ma=max(ma,a[i]&a[j]);
		}
	}
	cout<<ma;
	return 0;
} 
