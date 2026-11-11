#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else cout<<"0";
	int h=(int)s1[0]-'0',j=(int)s1[1]-'0';
	//cout<<h<<endl<<j<<endl;
	int o=(int)s2[0]-'0',k=(int)s2[1]-'0';
	//cout<<o<<endl<<k<<endl;
	//cout<<dyy<<hsh<<endl;
	if(c1==c2&&h==o&&j==k){
		cout<<"1";
	}else cout<<"0";
	char q=s1[2],p=s2[2];
	
	if(c1==c2&&h==o&&j==k){
		if(q=='F'){
			if(p=='D'){
					cout<<"1";
			}
			else cout<<"0";
		}
		if(q=='D'){
				if(p=='F'){
					cout<<"1";
				}
				else cout<<"0";
		}
		if(q=='C'){
				if(p=='B'){
						cout<<"1";
				}
				if(p=='A'){
					cout<<"1";
				}
				if(p!='A'&&p!='B')cout<<"0";
		}
		if(q=='B'){
				if(p=='C'){
						cout<<'1';
				}
				
				if(p=='A'){
					cout<<"1";
				}
				if(p!='A'&&p!='C')cout<<"0";
		}
		if(q=='A'){
				if(p=='B'){
						cout<<'1';
				}
				if(p=='C'){
					cout<<'1';
				}
				if(p!='C'&&p!='B')cout<<"0";
		}
		if((q=='F')||(q=='D')||(q=='B'))cout<<'1';
		if(q=='A'){
				if(p=='B'){
						cout<<"1";
				}
				else cout<<"0";
		}
		if(q=='C'){
				if(p=='B'){
						cout<<"1";
				}
				else cout<<"0";
		}
	}
	else cout<<"00";
	return 0;
}
