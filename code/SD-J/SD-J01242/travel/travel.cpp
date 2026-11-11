#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<"\n";
	}else{
		if(b[0]==d[0]&&b[1]==d[1]){
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
				if(b[2]+1==d[2])cout<<"1111\n";
				else cout<<"1110\n";
			}
			else{
				cout<<"1100\n";
				return 0;
			}
		}
		else {
			cout<<"1000\n";
			return 0;
		}
	}
	return 0;
}
