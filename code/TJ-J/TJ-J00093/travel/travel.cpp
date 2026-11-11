#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string co,so,ct,st;
	cin>>co>>so>>ct>>st;
	if(co==ct){
		cout<<1;
		string s = "";
		string ss = "";
		s+=so[0]+so[1];
		ss+=st[0]+st[1];
		if(s==ss){
			cout<<1;
			if((so[2]>='A'&&so[2]<='C'&&st[2]>='A'&&st[2]<='C')||(so[2]>='D'&&so[2]<='F'&&st[2]>='D'&&st[2]<='F')){
				cout<<1;
				if(abs(st[2]-so[2])==1){
					cout<<1;
				}
				else{
					cout<<0;return 0;
				}
			}
			else{
				cout<<"00";return 0;
			}
		}
		else{
			cout<<"000";return 0;
		} 
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
