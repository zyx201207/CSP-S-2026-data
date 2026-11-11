#include<bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("string.in","r",stdin);
	feropen("string.out","w",stdout);
	int m,n;
	cin >> m >> n;
	for(int i=1;i<=n;i++)
	{
		if(i<i-1)
		{
			cout << i-1;
		}
		else
		{
			cout << i;
		}
		
	}
return 0;
}
