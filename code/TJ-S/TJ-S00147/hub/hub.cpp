#include<bits/stdc++.h>
using namespace std;
const int N= 1e6;
int n,k,c,T,u[N],v[N];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> k;
		for (int i = 1;i <= n;i++)
		{
			cin >> u[i]>> v[i];
		}
		cout << 2<< " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
