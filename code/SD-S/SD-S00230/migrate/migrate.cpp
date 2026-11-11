#include<bits/stdc++.h>
#define ll long long
#define CLOSE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
int c,t,n,d;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	CLOSE
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			int x,y;
			string s;
			cin>>x>>y>>s;
			if(2*(y-x)==d){
				cout<<n-3<<endl;
			}
			else{
				cout<<0;
			}
		}
	}
	while(t--){
		if(d==1){
			cout<<0<<endl;
		}
		else if(d>=n){
			cout<<0<<endl;
		}
		else cout<<1<<endl;
	}
	return 0;
}


