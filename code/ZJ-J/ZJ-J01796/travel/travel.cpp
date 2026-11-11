#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		a=a*10+(c1[i]-'0');
		b=b*10+(c2[i]-'0');
	}
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	a=0,b=0;
	for(int i=0;i<=1;i++){
		a=a*10+(s1[i]-'0');
		b=b*10+(s2[i]-'0');
	}
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	a=s1[2]-'A',b=s2[2]-'A';
	if(a<3&&b>=3||a>=3&&b<3){
		cout<<"1100";
		return 0;
	}
	if(b>a)swap(a,b);
	if(a!=b+1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}