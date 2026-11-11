#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
string c1,s1,c2,s2;
int t=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&s1[2]!=s2[2]||
			s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'&&s1[2]!=s2[2]){
				cout<<1;
				if(abs(int(s1[2]-s2[2]))==1)
					cout<<1;
				else
					t=1;
			}
			else
				t=2;
		}
		else
			t=3;
	}
	else
		t=4;
	for(int i=1;i<=t;i++){
		cout<<0;
	}
	return 0;
}
