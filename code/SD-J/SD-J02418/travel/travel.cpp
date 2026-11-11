#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1)	cout<<1;
	else cout<<0;
	if(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1]) cout<<1;
	else cout<<0;
	if(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1]&&(r2[2]<='C'&&x2[2]<='C'||r2[2]>'C'&&x2[2]>'C'))
		cout<<1;
	else cout<<0;
	int p=x2[2]-r2[2];
	int sum=abs(p);
	if(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1]&&sum==1&&r2[2]!='C'&&x2[2]!='C') cout<<1;
	else cout<<0;
	return 0;
} 
