#include<bits/stdc++.h>
using namespace std;
#define int long long
//写不了一点 难 
const int Maxn=2e6+10;
int n,d,a[Maxn],c,t; 
int cnt,res=1;
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int dd;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dd=a[i]-a[i-1];
		}
		cout<<dd<<"\n";
	} 
	return 0;
} 
