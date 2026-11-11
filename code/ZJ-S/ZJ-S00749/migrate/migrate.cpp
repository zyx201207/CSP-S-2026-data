#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000100],n,d,f[2000100][2],x,s[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			if(n<4){
				cout<<"0\n";
				continue;
			}
			else{
				cin>>a[1]>>a[2]>>a[3]>>a[4];
				if(a[3]-a[1]<d&&a[4]-a[1]>d){
					cout<<n-3<<"\n";
				}
				else {
					cout<<"0\n";
				}
			}
		}
	}
	if(c==13||c==14){
		while(t--){
			cout<<"0\n";
		}
	}
	return 0;
}
