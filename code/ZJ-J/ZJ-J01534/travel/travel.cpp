#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int t1,t2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	c1=s2[2],c2=s4[2];
	t1=(s2[0]-'0')*10+s2[1]-'0';
	t2=(s4[0]-'0')*10+s4[1]-'0';
	if(s1!=s3){
		cout<<"0000"<<"\n";
	}else{
		cout<<1;
		if(t1==t2) cout<<1;
		else{
			cout<<"000";
			return 0;
		}
		if(c1=='A'&&c2=='B' || c1=='A'&&c2=='C' ||c1=='B'&&c2=='A' || c1=='B'&&c2=='C' || c1=='C'&&c2=='A' || c1=='C'&&c2=='B' || c1=='D'&&c2=='E' || c1=='E'&&c2=='D'){
			cout<<1;
		}else cout<<0;
		if(c1=='A'&&c2=='B' ||c1=='B'&&c2=='A' || c1=='B'&&c2=='C' || c1=='C'&&c2=='B' || c1=='D'&&c2=='E' || c1=='E'&&c2=='D'){
			cout<<1;
		}else cout<<0;
	}
	return 0;
}
