#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f=false,f1=false,f2=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> c1 >> s1 >> c2 >> s2;
	int b1=s1[2]-'A',b2=s2[2]-'A';
	if(c1==c2){
		f2=true;
		cout << 1;
	}
	else cout << 0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f2){
		f1=true;
		cout << 1;
	}
	else cout << 0;
	if(((b1>=3&&b2>=3)||(b1<=2&&b2<=2))&&f1){
		f=true;
		cout << 1;
	}else{
		cout << 0;
	}
	if(f&&abs(b1-b2)==1)cout<<1;
	else cout<<0;
	return 0;
}