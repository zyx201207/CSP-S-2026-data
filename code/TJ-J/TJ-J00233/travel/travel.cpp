#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a==c){
		cout<<'1';
		string nb,nd;
		nb=b[0]+b[1];
		nd=d[0]+d[1];
		if (nb==nd){
			cout<<'1';
			if ((b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C') || (b[2]>='D' && b[2]<='F' && d[2]>='D'&& d[2]<='F')){
				cout<<'1';
				if ((b[2]=='C' && d[2]=='D') || (b[2]=='D' && c[2]=='C')){
					cout<<'0';
				}
				else if (abs(b[2]-d[2]) == 1){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			} 
			else{
				cout<<"00";
				return 0;
			}
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
