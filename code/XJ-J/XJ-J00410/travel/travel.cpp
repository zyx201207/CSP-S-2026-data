#include<bits/stdc++.h>
using namespace std;
#define long long 
string c,s,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>c>>s>>c2>>s2;
	if(c[1]==c2[1]&&c[0]==c2[0]){
		cout<<1;
		if(s[1]==s2[1]&&s[0]==s2[0]){
			cout<<1;
			if((int(s[2])<='C'&&int(s2[2])<='C')||(int(s[2])<='F'&&int(s[2])>='D'&&int(s2[2])<='F'&&int(s2[2])>='D')){
				cout<<1;
				if(int(s[2])+1==int(s[2])||int(s[2])-1==int(s[2])||int(s2[2])+1==int(s[2])||int(s2[2])-1==int(s[2])){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<0<<0;
				return 0;
			}
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
return 0;
}