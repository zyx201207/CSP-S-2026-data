#include<bits/stdc++.h>
#include<cstdio>

using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1;
	string s1;
	string c2;
	string s2;
	cin >>c1>>c2>>s1>>s2;
	bool ok=1;
	for(int i=0;i<=1;i++)
	{
		
		if(c1[i]!=s1[i])
		{
			ok=0;
		}
	}
	if(ok){
		cout << 1;
	} 
	else {
		
		cout << 0<<0<<0<<0;
		return 0;
	}
	
	
		if(c2[1]==s2[1]&&c2[2]==c2[2])
		{
			cout << 1;
		}
		else
		{
			cout <<0<<0<<0;
			return 0;
		}
		
	
	
	 if((c2[2]>='A'&&c2[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||(c2[2]>='D'&&c2[2]<='E')&&(s2[2]>='D'&&s2[2]<='F'))
	 {
	 	cout <<1;
	 	
	 }
	 else
	 {
	 	cout <<0<<0;
			return 0;
	 }
	 if(c2[2]+1==s2[2]||c2[2]-1==s2[2])
	 {
	 	cout <<1;
	 }
	 else
	 {
	 	cout <<0;
	 }
	return 0;
}
