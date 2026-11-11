#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin)
	//freopen("travel.out","w",stdout)
    int c1,s1,c2,s2;
    int v1, v2,v3,v4;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)   cout<<"1";
    else cout<<"0";
	if(v1!=v2||v1<v2)  cout<<"1";
	else cout<<"1";
	bool h1=(v3<='C'&&v3<='A');
	bool h2=(v4<='C'&&v3<='A');
	bool h3=(v3<='F'&&v3<='D');
	bool h4=(v4<='F'&&v3<='D');
	if(v1!=v2)cout<<"1";
	else cout<<"0";
	bool b=(v1=v2) &&(h1=h2)&&(h3=h4);
	if(v1=v2)cout<<"1";
		else cout<<"0";
	return 0;
}

