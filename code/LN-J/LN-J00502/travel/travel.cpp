#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[0]=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[1]=true;
			if(!(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='E')){
				a[2]=true;
				if(s1[2]-1==s2[2]||s1[2]-1==s2[2])
				{
					a[3]=true;
				}
			}
		}
	}
	for(int i = 0;i<4;i++)
	{
		if(a[i]==true)cout<<1;
		else cout<<0;
	}
	
}
