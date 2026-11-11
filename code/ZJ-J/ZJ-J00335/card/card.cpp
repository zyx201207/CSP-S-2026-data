#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N];
signed main(){
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
	return 0;
} 

