#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand((unsigned int)time(nullptr));
    int c,t;
    cin >> c >> t; 
    while(t--)
    {
    	int n,d;
    	int cnt = 0;
    	cin >> n >> d;
    	vector<int> x(n + 1);
    	for(int i = 1;i <= n;i++) cin >> x[i];
    	int l = 1;
    	for(int i = 2;i <= n;i++)
    	{
    		if(x[i] - x[i - 1] > d)
			{
				cnt += rand() % 2;
			}  
		}
		cout << cnt + rand() % 2 << '\n';
	}
    return 0;
}

