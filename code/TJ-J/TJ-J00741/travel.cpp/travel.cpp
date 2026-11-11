#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=c1.size(),a2=c2.size(),b1=0,b2=0;
	int x1=0,x2=0;
	while(x1!=a1)
	{
		b1+=(c1[x1]-'0')*pow(10,a1-x1-1);x1++;
	}
	while(x2!=a2)
	{
		b2+=(c2[x2]-'0')*pow(10,a2-x2-1);x2++;
	}
	if(b1==b2)
cout<<"1";
	else {
	cout<<"0000";
return 0;}
	
	
	b1=0,b2=0,a1=s1.size(),a2=s2.size();
for(int i=0;i<=1;i++)
		b1+=(s1[i]-'0')*pow(10,a1-i-2);
int l1=s1[2];
for(int i=0;i<=1;i++)	
		b2+=(s2[i]-'0')*pow(10,a2-i-2);
	
	int l2=s2[2];
	
	if(b1==b2)
	cout<<"1";
	else{
		cout<<"000";return 0;
	}
	
	if(l1=='D'||l1=='F'){
		if(l2=='F'||l2=='D'){cout<<"11";return 0;}else{cout<<"00";return 0;}
		}
		
	else
		if(l2!='F'&&l2!='D'){
	cout<<'1';
	if(l1+1==l2||l2+1==l1)
	cout<<'1';
	else cout<<'0';
	}else cout<<"00";
	return 0;
} 
