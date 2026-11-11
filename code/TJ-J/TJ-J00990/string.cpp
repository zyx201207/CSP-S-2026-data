#include<bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("string.in","r",stdin);
	feropen("string.out","w",stdout);
	int n,c1,ai;
	cin >> n >> c1 >> ai;
	for(int i=1;i<=n;i++)
	{
		if(n!=i)
		{
			cout << "n\";
		}
		else
		{
			cout << c1*ai;
		}
	}
return 0;
}
