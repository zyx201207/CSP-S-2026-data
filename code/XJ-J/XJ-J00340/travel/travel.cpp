#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	cin>>c1>>c2;
	char a[20],b[20];
	if(c1==c2)
		cout<<'1';
	else
		cout<<'0';
	if(a[1]==b[1])
		cout<<"1";
	else
		cout<<'0';
	if(a[2]>='A'&&b[2]<='C'){
		if(a[2]>='D'&&b[2]<='F')
			cout<<"11";
	else
		cout<<"00";}
	return 0;
}