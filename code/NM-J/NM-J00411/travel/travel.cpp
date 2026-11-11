#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string str1;
		string str2;
		str1=s1;
		str2=s2;
		str1.erase(str1.begin()+2);
		str2.erase(str2.begin()+2);
		if(str1==str2){
			cout<<"1";
			string a;
			string b;
			a+=s1[2];
			b+=s2[2];
			if(a[0]=='A'||a[0]=='B'||a[0]=='C'){
				if(b[0]=='A'||b[0]=='c'||b[0]=='B'){
					cout<<"1";
					if(a[0]=='A'&&b[0]=='B'){
						cout<<"1";
					}else if(a[0]=='B'&&b[0]=='A'){
						cout<<"1";
					}else if(a[0]=='B'&&b[0]=='C'){
						cout<<"1";
					}else if(a[0]=='C'&&b[0]=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}else{
				if(b[0]=='F'||b[0]=='D'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
