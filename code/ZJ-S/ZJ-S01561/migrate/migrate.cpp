#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll x[2000010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,a;
	cin>>c>>t;
	while(t--){
		if(c==11||c==12){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			x[1]=x[2]-x[1];
			a=d/x[1];
			if(a>=2){
				if(2*a<=n)
					cout<<n-2*a<<endl;
				else cout<<0<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}
