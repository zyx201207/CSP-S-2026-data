//SN-J00746 张宸熙 西安市第十二中学 
#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f=0,fl;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			cout<<"000";
			f=1;
			break;
		}
	}
	if(f==0){
		cout<<'1';
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				cout<<'1';
				fl=1;
			}else{
				cout<<"00";
				return 0;
			}	
		}
		if(b[2]=='D'||b[2]=='F'){
			if(d[2]=='D'||d[2]=='F'){
				cout<<'1';
				fl=2;
			}else{
				cout<<"00";
				return 0;
			}	
		}
		if(fl==1){
			if(b[2]=='A'){
				if(d[2]=='B'){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else if(b[2]=='B'){
				cout<<'1';
			}else{
				if(d[2]=='B'){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}
		}else if(fl==2){
			cout<<'1';
		}	
	}
}
