#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
        s1=s1+"00";
        s2=s2+"00";
		cout<<1;
		string a=s1.substr(0,2);
//		cout<<a;
		string b=s2.substr(0,2);
		string c=s1.substr(2,1);
		string d=s2.substr(2,1);
//		cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
		if(a==b){
			cout<<"1";
			if((c=="F"&&d=="D")||(c=="D"&&d=="F")) cout<<"11";
			else if((c=="A"&&d=="B")||(c=="B"&&d=="A")) cout<<"11";
			else if((c=="C"&&d=="B")||(c=="B"&&d=="C")) cout<<"11";
			else if((c=="A"&&d=="C")||(c=="C"&&d=="A")) cout<<"10";
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
