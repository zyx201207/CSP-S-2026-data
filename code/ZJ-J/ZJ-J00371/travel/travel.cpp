#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	string t1="",t2="";
	t1+=s1[0],t1+=s1[1];
	t2+=s2[0],t2+=s2[1];
	if(t1!=t2){
		cout<<"000";
		return 0;
	} 
	cout<<"1";
	char a=s1[2],b=s2[2];
	if(a>b)swap(a,b);
	if(a!='D'&&(b=='D'||b=='F')){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(a=='A'&&b!='B'||a=='B'&&b!='C'||a=='D'&&b!='F'){
		cout<<"0";
	}
	else cout<<"1";
	return 0;
} 
