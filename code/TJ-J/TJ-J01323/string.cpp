#include <bits/stdc++.h>
using namespace std;
string c,v;
int n,cnt,a;
int main()

{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >>n;
	while (n--)
	{
		cin>>a>>c;
		v=c;
		
		
		for (int i=0;i<=a-1;i++) 
		{
			
			for (int j=a-1;j>=1;j--)
			{
				
				if (v[j]==c[i]) cout <<'k';
				
				if (c[j]==c[i])
				cnt++;
				
			}
			
		}
	}
	cout <<cnt;
	
	return 0;
}
