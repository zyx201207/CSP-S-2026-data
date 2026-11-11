#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3) cout<<"0000";
	else{
		if(s2[0]!=s4[0]||s2[1]!=s4[1]) cout<<"1000";
		else{
			int k=abs(s2[2]-s4[2]);
			if(k>2) cout<<"1100";
			else{
				if(s2[2]=='D'||s2[2]=='F'||s4[2]=='D'||s4[2]=='F') 
				{
					if(k==2) cout<<"1111";
					else cout<<"1100"; 
				}
				else{
					if(k==1)cout<<"1111";
					else cout<<"1110";
				}
				}
			}
		}
	return 0;
}
