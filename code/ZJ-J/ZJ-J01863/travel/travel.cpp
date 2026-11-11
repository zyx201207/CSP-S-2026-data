#include<bits/stdc++.h>
using namespace std;
string cl,sl,cr,sr;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cl>>sl>>cr>>sr;
	bool f=0,b=0,fl=0,flg=0;
	if(cl==cr)
	{
			f=1;
		if(sl[0]==sr[0]&&sl[1]==sr[1])
		{
			b=1;
			if((sl[2]<='C'&&sr[2]<='C')||(sl[2]>='D'&&sr[2]>='D'))
			{
				fl=1;
				if(abs(sl[2]-sr[2])==1)
					flg=1;
			}	
				
		}
			
	}
	cout<<(f?1:0);
	cout<<(b?1:0);
	cout<<(fl?1:0);
	cout<<(flg?1:0);
	return 0;
}
