#include<bits/stdc++.h>//张哲 庆安初级中学 SN-J00787
using namespace std;
int c1,c2;
string s1,s2;
int p1,p2;
char w1,w2;
int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;	
	p1=(s1[0]-'0')*10+s1[1]-'0';
	w1=s1[2];
	p2=(s2[0]-'0')*10+s2[1]-'0';
	w2=s2[2];
	if(c1==c2)
	{
		cout<<1;
		if(p1==p2)
		{
			cout<<1;
			if((w1=='C' && w2=='D' ) || (w1=='D' && w2=='C')) cout<<0<<0;
			else 
			{
				cout<<1;
				if(w1-w2==1 || w2-w1==1) cout<<1;
				else cout<<0;
			}
		} 
		else cout<<0<<0<<0;
	} 
	else cout<<0<<0<<0<<0;
	return 0;
}
