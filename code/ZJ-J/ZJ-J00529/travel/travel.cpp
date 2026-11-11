#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool f1=false,f2=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int a,b;
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b){
		cout<<"1";
		f1=true;
	}else{
		cout<<"0";
	}
	if(s1[2]<='C' and s2[2]<='C' and f1){
		cout<<"1";
		f2=true;
	}else if(s1[2]>='D' and s2[2]>='D' and f1){
		cout<<"1";
		f2=true;
	}else{
		cout<<"0";
	}
	if(f2 and int(abs(s1[2]-s2[2]))==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	cout<<"\n";
	return 0;
}