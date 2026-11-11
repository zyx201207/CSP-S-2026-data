#include<bits/stdc++.h>
using namespace std;
string sa,sb,sc,sd;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>sb>>sc>>sd;
	a=int(sb[0]-'0')*10+int(sb[1]-'0');
	b=int(sd[0]-'0')*10+int(sd[1]-'0');
	if(sa==sc){
		cout<<"1";
		if(a==b) {
			cout<<"1";
			if((sb[2]<='C'&&sd[2]<='C')||(sb[2]>'C'&&sd[2]>'C')){
				cout<<"1";
				if(sb[2]+1==sd[2]||sd[2]+1==sb[2]) cout<<"1";
				else cout<<"0";
			} 
			else cout<<"00";
			
		}
		else cout<<"000";
		
	}
	else cout<<"0000";
	
	return 0;
}
