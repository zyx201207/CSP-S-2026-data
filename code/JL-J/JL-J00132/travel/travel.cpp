#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[100]={2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,},s1[100],c2[100]={2,3,4,5,6,7,8,9,10,11,12,13,14,15,17},s2[100];
	for(int i= 1;i <= c1.size();i++)
	{
		cin >> c1[i]>> c2[i];
		if(c1=c2)
		{
		cout << "1";
		}
		else
		{
			cout >> "0";
		}
		for(int j=0;j<=s1.size();j++){
		if(s1[j]+=s2[j])
			{
			cout << "1";
			else
				{
					cout<<"0";
				}
			}
		}
		
	}	
			return 0;
}
