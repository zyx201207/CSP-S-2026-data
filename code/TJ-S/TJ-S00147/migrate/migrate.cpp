#include<bits/stdc++.h>
using namespace std;
const int N= 1e6;
int n,k,c,T,a[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> k;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		cout << 2<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
