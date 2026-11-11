#include <bits/stdc++.h>
using namespace std;
int c1,c2;
char a,b,c,d,e,f;
string s1,a1,b1,s2,d1,e1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	/*int a,b;
	cin>>a>>b;
	cout<<a+b;
	//ceil floor sort sprt pow */
	//cin>>a;
	cin>>c1>>a>>b>>c>>c2>>d>>e>>f;
	a1=a;
	b1=b;
	s1=a1+b1;
	d1=d;
	e1=e;
	s2=d1+e1;
	//cout<<s2<<' '<<c1<<endl;
	if(c1!=c2){
		//m="0000";
		cout<<"0000";
		return 0;
	}

	if(s1!=s2){
		//m="1000";
		cout<<"1000";
		return 0;
	}
	if(c<='C'&&f<='C'||c>='D'&&f>='D'){
		if(c=='A'&&f=='C'||c=='C'&&f=='A'){
			cout<<"1110";
			return 0;
		}
		cout<<"1111";
		
	}
	else {
		//m="1100";
		cout<<"1100";
		return 0;
	}

	
	//cout<<"no";
	return 0;
} 
