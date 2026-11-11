#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
		if(b[1]==d[1]&&b[0]==d[0]){
			cout<<"1";
			if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
				cout<<"11";
			}else if(b[2]=='A'){
				if(d[2]=='B'){
					cout<<"11";
				}else if(d[2]=='C'){
					cout<<"10";
				}else{
					cout<<"00";
				}
			}else if(b[2]=='B'){
				if(d[2]=='A'||d[2]=='C'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else if(b[2]=='C'){
				if(d[2]=='A'){
					cout<<"10";
				}else if(d[2]=='B'){
					cout<<"11";
				}else{
					cout<<"00";
				}
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
/*

I will AFO...

who create T3? and xor or? It makes me AFO!!!

myz I love you.



*/
