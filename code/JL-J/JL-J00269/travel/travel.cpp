#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	int cr=stoi(c1),cx=stoi(c2);
	if(cr==cx)
	{
		ans+='1';
		int sr=stoi(s1.substr(0,2)),sx=stoi(s2.substr(0,2));
		if(sr==sx)
		{
			ans+='1';
			int numr=s1[2]-'A',numx=s2[2]-'A';
			if((numr<3&&numx<3)||(numr>=3&&numx>=3))
			{
				ans+='1';
				if(abs(numr-numx)==1)
					ans+='1';
				else
					ans+='0';
			}
			else
				ans+="00";
			
		}
		else
			ans+="000";
	
	}
	else
		ans+="0000";	
	cout<<ans<<endl;
	return 0;
}
