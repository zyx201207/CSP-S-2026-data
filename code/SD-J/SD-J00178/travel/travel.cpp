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
	if(c1!=c2) {
		cout<<"0000";
		return 0; 
	}
	cout<<'1';
	string a=s1.substr(0,2);
	string b=s2.substr(0,2);
	if(a!=b) {
		cout<<"000";
		return 0;
	}
	cout<<'1';
    char x=s1[2],y=s2[2];
    if(((x>='A'&&x<='C')&&(y>='A'&&y<='C'))||(x>='D'&&y>='D')){
    	cout<<'1';
    	if(x>y) swap(x,y);
    	if((char)(x+1)==y){
    		cout<<'1';
		}
		else cout<<'0';
	}
	else cout<<"00";
	return 0;
}
