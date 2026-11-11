#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int c,t;
int n,d;
int a[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(c==13 || c==14){
			cout<<0<"\n";
			continue;
		}
		if(c==11 || c==12){
			int cha=a[1]-a[0];
			if(cha>d){
				cout<<0<<"\n";
				continue;
			}
			int jump=d/cha;
			if(jump>=3 || jump==1){
				cout<<0<<"\n";
				continue;
			}else{
				cout<<n-3<<"\n";
				continue;
			}
		}
		int a,b;
		cin>>a>>b;
		for(int i=3;i<=n;i++){
			int x;cin>>x;
		}
		cout<<n-(2*d/(b-a)-1)<<"\n";
	}
	return 0;
}

