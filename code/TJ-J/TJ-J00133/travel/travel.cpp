#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c11,s11,c22,s22;
	cin>>c11>>s11>>c22>>s22;
	if(c11 != c22){
		cout<<"0000";
		return 0;
	}
	if(s11[0] != s22[0]||s11[1] != s22[1])
	{
		cout<<"1000";
		return 0;
	}
    int n,m;
	n = s11[2];m = s22[2];
	if(n<=67&&m<=67)
	{
		if(n - m == 1||m - n == 1)
		{
			cout<<"1111";
		}
		else{
			cout<<"1110";
		}
	}
	else if(n>67&&m>67)
	{
		cout<<"1111";
	}
	else{
		cout<<"1100";
	}
	return 0;
} 
