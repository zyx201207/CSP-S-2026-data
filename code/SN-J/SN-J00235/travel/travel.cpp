#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int f1(string s1,string s2)
{
	string a1,a2;
	a1=s1[0];
	a2=s2[0];
	a1+=s1[1];
	a2+=s2[1];
	if(a1==a2){
		return 0;
	}
	return 1;
}
int f2(string s1,string s2)
{
	int a1,a2;
	if(s1[2]<='C'){
		a1=1;
	}
	else{
		a1=2;
	}
	if(s2[2]<='C'){
		a2=1;
	}
	else{
		a2=2;
	}
	if(a1==a2){
		return 0;
	}
	return 1;
}
int f3(string s1,string s2)
{
	int a1=s1[2],a2=s2[2];
	if(abs(a1-a2)==1){
		return 0;
	}
	return 1;
}
int main()
{
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(f1(s1,s2)){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(f2(s1,s2)){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(f3(s1,s2)){
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}
