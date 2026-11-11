#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;


int main(){
	
	cin.tie(0);
	cout.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int id1=0,id2=0;
	for(int i=c1.size()-1;i>=0;i--)
	{
		id1=id1*10+c1[i]-'0';
	}
	for(int i=c2.size()-1;i>=0;i--)
	{
			id2=id2*10+c2[i]-'0';
	}
	if(id1==id2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	int p1=0,p2=0;
	for(int i=s1.size()-2;i>=0;i--){
		p1=p1*10+s1[i]-'0';
	}
	for(int i=s2.size()-2;i>=0;i--){
		p2=p2*10+s2[i]-'0';
	}
	if(p1==p2)
	{
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	int a=s1.size()-1,b=s2.size()-1;
	
	if(((s1[a]<='C')&&(s2[b]<='C'))||((s1[a]>'C')&& (s2[b]>'C'))){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[a]-s2[b])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
