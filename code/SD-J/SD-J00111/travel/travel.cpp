#include<bits/stdc++.h> 
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int f1,f2;
	f1=(s1[0]-'0')*10+s1[1]-'0';
	f2=(s2[0]-'0')*10+s2[1]-'0';
	//cout<<f1<<endl<<f2<<endl;
	if(f1==f2){
		cout<<1;	
	}else {
		cout<<0<<0<<0;
		return 0;
	}
	int e1,e2;
	e1=s1[2];
	e2=s2[2];
	if((e1<='C'&&e2<='C')||(e1>'C'&&e2>'C')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(e1=='F')e1='E';
	if(e2=='F')e2='E';
	if(abs(e1-e2)==1)cout<<1;
	else cout<<0;
	return 0;
}
