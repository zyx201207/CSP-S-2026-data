#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string stra,strb;
	cin>>a>>stra>>b>>strb;
	if(a==b)
	{
		cout<<1;
		if(stra[0]+stra[1]==strb[0]+strb[1])
		{
			cout<<1;
			char s1=stra[2],s2=strb[2];
			if((s1>='A' && s2>='A' && s1<='C' && s2<='C')  ||  (s1=='D' && s2=='F')  ||  (s1=='F' && s2=='D'))
			{
				cout<<1;
				if((s1=='D' && s2=='F')  ||  (s1=='F' && s2=='D')  ||  (s1=='A' && s2=='B')  ||  (s1=='B' && s2=='A')  ||  (s1=='B' && s2=='C')  ||  (s1=='C' && s2=='B'))
				{
					cout<<1; 
				} 
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
