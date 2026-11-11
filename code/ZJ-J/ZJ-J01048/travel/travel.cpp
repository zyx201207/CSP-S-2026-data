#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	bool flag1=0 , flag2=0 , flag3=0 , flag4=0;
	if(c1==c2)
	{
		flag1=1;
		if(((s1[0]-'0')*10+s1[1]-'0')==((s2[0]-'0')*10+s2[1]-'0'))
		{
			flag2=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
			{
				flag3=1;
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
				{
					flag4=1;
					cout << flag1 << flag2 << flag3 << flag4;
				}
				else
				{
					cout << flag1 << flag2 << flag3 << flag4;
				}
			}
			else
			{
				cout << flag1 << flag2 << flag3 << flag4;
			}
		}
		else
		{
			cout << flag1 << flag2 << flag3 << flag4;
		}

	}
	else
	{
		cout << flag1 << flag2 << flag3 << flag4;
	}
	
	return 0; 
}
