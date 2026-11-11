#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string x,y;
	int n,m;
	for(int i=0;i<s1.size()-1;i++){
		x+=s1[i];
	}
	for(int i=0;i<s2.size()-1;i++){
		y+=s2[i];
	}
	n=max((s1[s1.size()-1]-'A'),(s2[s2.size()-1]-'A'));
	m=min((s1[s1.size()-1]-'A'),(s2[s2.size()-1]-'A'));
	bool a,b,c;
	if(c1==c2)
		a=1;
	else
		a=0;
	if(x==y && a==1)
		b=1;
	else
		b=0;
	if(a==1 && b==1 && (n<=2 && m<=2)||(n>=3 && m>=3))
	c=1;
	else
	c=0;
	if(a==1)
	cout<<"1";
	else
	cout<<"0";
	if(b==1)
	cout<<"1";
	else
	cout<<"0";
	if(c==1)
	cout<<"1";
	else
	cout<<"0";
	if(a==1 && b==1 && c==1)
	cout<<"1";
	else
	cout<<"0";
	return 0;
}
