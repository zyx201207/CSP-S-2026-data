#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
string c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
	}else{
		cout<<"1";
		if(c[0]!=d[0]||c[1]!=d[1]){
			cout<<"000";
		}else{
			cout<<"1";
			if(c[2]<='C'&&d[2]>='D'||c[2]>='D'&&d[2]<='C'){
				cout<<"00";
			}else{
				cout<<"1";
				if(c[2]=='A'&&d[2]=='C'||c[2]=='C'&&d[2]=='A'){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		}
	}
	return 0;
}