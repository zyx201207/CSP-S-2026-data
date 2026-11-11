#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}
	cout << "1";
	string a1,a2;
	a1.push_back(s1[0]);
	a1.push_back(s1[1]);
	a2.push_back(s2[0]);
	a2.push_back(s2[1]);
	if(a1!=a2){
		cout << "000";
		return 0;	
	}
	cout << "1";
	char t1=s1[2];
	char t2=s2[2];
	if((t1<='C'&&t2<='C')||(t1>='D'&&t2>='D')){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	int x1=s1[2]-'A';
	int x2=s2[2]-'A';
	if(x1<x2) swap(x1,x2);
	int x=x1-x2;
	if(x==1) cout << 1;
	else cout << 0;
	return 0;
}
