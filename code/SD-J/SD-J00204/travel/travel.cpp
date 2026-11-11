#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2,s1,s2;
bool pd(string a,string b){
	if((a[2]<='C'&&a[2]>='A'&&b[2]<='C'&&b[2]>='A')||(a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F')){
		return 1;
	}
	return 0;
}
bool pd1(string a,string b){
	if(abs(a[2]-b[2])==1||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')){
		return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==s1&&c2.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==s1&&c2.substr(0,2)==s2.substr(0,2)&&pd(c2,s2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==s1&&pd(c2,s2)&&pd1(c2,s2)&&c2.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}


