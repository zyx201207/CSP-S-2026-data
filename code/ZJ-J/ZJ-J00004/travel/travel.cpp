#include<bits/stdc++.h>
using namespace std;
void check(char a,char b){
	int k=(int)a-'A'+1,k2=(int)b-'A'+1;
	if(k<=3&&k2<=3){
		cout<<"1";
		if(abs(k-k2)==1)cout<<"1";
		else cout<<"0";
		exit(0);
	}
	if(k>=4&&k2>=4){
		cout<<"11";
		exit(0);
	}
	cout<<"00";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<"1";
	else {cout<<"0000";exit(0);}
	string k=s2.substr(0,2),k2=s4.substr(0,2);
	if(k==k2)cout<<"1";
	else {cout<<"000";exit(0);}
	check(s2[2],s4[2]);
	return 0;
} 
