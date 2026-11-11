#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int flag1=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else cout<<0;
	int p1,p2;
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(p2==p1&&c1==c2)
		cout<<1;
	else cout<<0;
	char z1,z2;
	z1=s1[2],z2=s2[2];
	if(p2==p1&&c1==c2)
	{
		if(z1>='A'&&z1<='C'&&z2>='A'&&z2<='C')
		{
			cout<<1; flag1=1;
		}	
		else
		{
		 if(z1>='D'&&z1<='F'&&z2>='D'&&z2<='F'&&z1!='E'&&z2!='E')
		 {
		 cout<<1; flag1=1;
		 }
			
			else{ cout<<0;
			} 
		}
	}
	else
	{
	cout<<0;
	} 
	if(flag1==1){
		if((z1=='A'&&z2=='B')||(z1=='B'&&z2=='A')||(z1=='B'&&z2=='C')||(z1=='C'&&z2=='B')||(z1=='D'&&z2=='F')||(z1=='F'&&z2=='D'))
		cout<<1;
			else cout<<0;
	}
	else cout<<0;
	return 0;
}
//100
