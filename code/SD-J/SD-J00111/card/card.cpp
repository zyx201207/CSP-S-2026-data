#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=5*1e5+10;
int n,m;
int a[N];
int b[N];
int c[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" "<<b[i]<<" ";
	}
	return 0;
}

