#include<bits/stdc++.h>
#define int long long
#define uint usigned long long
#define fst ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,m,a[N],sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fst;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=a[2]-a[1],p=1;
	if(m<t) cout<<0;
	while(m>=0){
		m-=t*p;
		sum++;
		p++;
	}
	cout<<sum;
	return 0;
}
