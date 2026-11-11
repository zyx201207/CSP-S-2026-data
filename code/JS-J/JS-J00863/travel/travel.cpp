#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if((a[0]==c[0])&&(a[1]==c[1])){
		cout<<'1';
		if((b[0]==d[0])&&(b[1]==d[1])){
			cout<<'1';
			bool flag=false;
			if(((b[2]<=67)&&(d[2]<=67))||((b[2]>=68)&&(d[2]>=68))){
				cout<<'1';
				flag=true;
			}
			else cout<<'0';
			if(flag){
				if((b[2]-d[2]==1)||(d[2]-b[2]==1)){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
			else cout<<'0';
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
