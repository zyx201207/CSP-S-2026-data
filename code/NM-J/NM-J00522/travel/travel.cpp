#include<bits/stdc++.h> 
using namespace std;
string a,x,b,r;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>r;
	if(a!=b) {cout<<0<<0<<0<<0;return 0;}
    cout<<1;
	if(x[1]==r[1]||x[2]==r[2]) cout<<1;
	else {cout<<0<<0<<0;return 0;}
	if(((x[3]=='A'||x[3]=='B'||x[3]=='C')&&(r[3]!='D'||r[3]!='F'))||((r[3]=='A'||r[3]=='B'||r[3]=='C')&&(x[3]!='D'||x[3]!='F'))) cout<<1;
	else {cout<<0<<0;return 0;}
	if((r[3]=='A'&&x[3]!='C')||(x[3]=='A'&&r[3]!='C')) cout<<1;
	else {cout<<0;return 0;}
    fclose(stdin);
	fclose(stdout);
	return 0;
}
