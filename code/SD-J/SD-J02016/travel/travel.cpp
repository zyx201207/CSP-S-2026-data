#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=s1[2]-'0';
	int y=s2[2]-'0';
	bool flag=0;
	if (c1==c2){
		cout<<1;
		flag=1;
	}
	else{
		cout<<0;
	}
	if (flag==1){
		if (s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			flag=1;
		}
		else{
			cout<<0;
			flag=0;
		}
	}
	else{
		cout<<0;
	}
	if (flag==1){
		if (x<='C'-'0'&&y>='D'-'0'||y<='C'-'0'&&x>='D'-'0'){\
			cout<<0;
			flag=0;
		}
		else{
			cout<<1;
			flag=1;
		}
	}
	else{
		cout<<0;
	}
	if (flag==1){
		if (abs(x-y)==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
