#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
	}
	else{
		cout<<"0000";
		cout<<endl;
		return 0;
	} 
	if(s2[0]+s2[1]==s4[0]+s4[1]){
		cout<<"1";
	}
	else{
		cout<<"000"<<endl;	
		return 0;	
	} 
	if((s2[2]>='D'&&s4[2]<='D') || (s2[2]<'D'&&s4[2]<'D')){
		cout<<"1";
	}
	else{
		cout<<"00"<<endl;
		return 0;
	}
	int a1,a,b;
	a=(int)s2[2]-'A';
	b=(int)s4[2]-'A';
	a1=abs(a-b);
	if(a1==1){
		cout<<"1"<<endl; 
	}
	else{
		cout<<"0"<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


