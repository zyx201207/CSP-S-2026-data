#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,c,b,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		if(c[0]==d[0]&&c[1]==d[1]){
			cout<<1;
			if(c[2]<='C'&&d[2]<='C'){
				cout<<1;
				if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(c[2]>'C'&&d[2]>'C'){
				cout<<11;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
