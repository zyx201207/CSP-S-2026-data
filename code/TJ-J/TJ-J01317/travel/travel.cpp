#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int b1=(s1[0]-'0')*10+s1[1]-'0',b2=(s2[0]-'0')*10+s2[1]-'0';
	char x1=s1[2],x2=s2[2];
	if(c1==c2){
		cout << 1;
		if(b1==b2){
			cout << 1;
			if((x1<='C'&&x1>='A')&&(x2<='C'&&x2>='A')){
				cout<<1;
				if((x1=='A'&&x2=='C')||(x1=='C'&&x2=='A')){
					cout << 0;
				}
				else{
					cout << 1;
				}
			}
			else if((x1<='F'&&x1>='D')&&(x2<='F'&&x2>='D')){
				cout << 1;
				cout << 1;
			}
			else{
				cout << 0;
				cout << 0; 
			}
		}
		else{
			cout << 0;
			cout << 0; 
			cout << 0;
		}
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
	}
	
	return 0;
}
