#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
const int INF=2e18,N=5e5+10;
int n,m,a[N];
map<int,int> mp;
signed main(){
	IOS;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		mp[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(i==a[n]){
			cout<<n<<' ';
		}
		else{
			cout<<mp[i]<<' ';
		}
	}
	return 0;
} 
