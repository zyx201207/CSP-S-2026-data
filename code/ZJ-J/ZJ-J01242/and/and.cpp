#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,M;
ll a[600000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	m--;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	M=a[n];
	for(int i=n-1;i>=1;i--){
		while(m>0){
			M&=a[i];
			m--;
		}
	}
	cout<<M;
	return 0;
}
