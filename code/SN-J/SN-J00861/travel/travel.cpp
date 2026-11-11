#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a=0,b=0;
	char c[3],d[3];
	
	cin>>a;
	for(int i=0;i<3;i++){
		cin>>c[i];
	}
	cin>>b;
	for(int i=0;i<3;i++){
		cin>>d[i];
	}

	if(a == b) {
		cout<<1;
		if(c[0] == d[0] && c[1] == d[1]){
			cout<<1;
			
			if( (((c[2]=='A')||(c[2]=='B')||(c[2]=='C')) && ((d[2]=='A')||(d[2]=='B')||(d[2]=='C'))) || (((c[2]=='D')||(c[2]=='F')) && ((d[2]=='F')||(d[2]=='D'))) ){
				cout<<1;
				
				if((c[2]-d[2] == 1) || (c[2]-d[2] == -1)){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<0;
				cout<<0;
				return 0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
			return 0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	return 0;
}


