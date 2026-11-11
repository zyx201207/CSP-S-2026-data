#include <bits/stdc++.h> 
using namespace std;
string c1,c2,s1,s2;
int n=1111,m=0000,p=1000;
int main(){
	cin>>c1>>s1>>c2>>s2;
	freopen("travel3.in","r",stdin);
	//cin>>c1>>s1>>c2>>s2;
	freopen("travel3.out","w",stdout);
	if(c1==c2&&s1<s2){
		cout<<n;
	}
	if (c1!=c2){
		cout<<m;
	}
	if (c1==c2&&s1>s2){
		cout<<p;
	}
	
	
	return 0;
}

