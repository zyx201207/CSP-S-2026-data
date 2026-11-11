#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using namespace std;
const int N=2e5+5;
int n,m;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-1]<<endl;
	return 0;
} 
