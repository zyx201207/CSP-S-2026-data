#include<bits/stdc++.h>
using namespace std;
string a;
int b=0,c=0;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	cin>>a;
	for(int i=0;i<2;i++){
		if (a[i]!=a[i+7]) {
			cout<<"0000";
			return 0;
		}
	}
	b+=1000;
	for(int i=0;i<2;i++){
		if (a[i+3]!=a[i+10]) {
			cout<<b;
			return 0;
		}
	}
	b+=100;
	if ((a[12]=='A' and (a[5]=='B' or a[5]=='C')) || (a[12]=='B' and (a[5]=='A' or a[5]=='C'))||(a[12]=='C' and (a[5]=='A' or a[5]=='B'))||(a[12]=='D' and a[5]=='F') ||(a[12]=='F' or a[5]=='D')) {
		b+=10;
		if (a[12]-a[5]==1 || a[5]-a[12]==1 || a[12]=='F'||a[12]=='D') b+=1;
		}
	cout<<b;
	return 0;
}