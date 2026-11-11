#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string s1,s2,z1,z2;
	cin>>s1>>z1>>s2>>z2;
	if(s1==s2) cout<<1;
	else{
	cout<<0;	
	} 
	if(s1==s2&&z1[0]==z2[0]&&z1[1]==z2[1]) cout<<1;
	else cout<<0;
	if(s1==s2&&z1[0]==z2[0]&&z1[1]==z2[1]&&((z1[2]>'C'&&z2[2]>'C')||(z1[2]<'D'&&z2[2]<'D'))) {	
	cout<<1;
	long long sum=z1[2]-z2[2];
	if(sum<0) sum*=-1;
	if(sum==1) cout<<1;
	else cout<<0;
	}
	else cout<<"00";
	
	return 0;
 } 
