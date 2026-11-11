#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1])
		{
//			cout<<s1<<' '<<s2<<'\n';
			cout<<1;
			int l1=0,l2=0;
			if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C')
				l1=1;
			else l1=0;
			if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C')
				l2=1;
			else l2=0;
			if(l1==l2)
			{
//				cout<<"Y";
				cout<<1;
				if(s1[2]+1==s2[2] or s1[2]-1==s2[2])
					if(max(s1[2],s2[2])<='C')
						cout<<1;
				else if(s1[2]=='D' and s2[2]=='F')
					cout<<1;
				else if(s1[2]=='F' and s2[2]=='D')
					cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
