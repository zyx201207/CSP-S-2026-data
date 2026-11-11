#include <bits/stdc++.h>>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans="";
	cin>>c1>>s1>>c2>>s2;
	int e=s1.size()-1,r=s2.size()-1;
	if(c1==c2){
		ans+="1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans+="1";
			int x=s1[2],y=s2[2];
			if(x>=65 && x<=67 && y>=65 && y<=67){
				ans+="1";
				if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1)
					ans+="1";
				else ans+="0";
			}
			else if(x>=68 && x<=70 && y>=68 && y>=70){
				ans+="1";
				if(x-y==1 || y-x==1)
					ans+="1";
				else ans+="0";
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";

	cout<<ans;
	return 0;
}	