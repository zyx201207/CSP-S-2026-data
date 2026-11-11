#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;



int energy[N];

int dfs(int step , int cnt , int n , int m)
{
    if(step >= m)
    {
        return cnt;
    }

    for(int i = 1; i <= n; i++)
    {
        energy[i] + 1;

        int t[100005] = {0};
        int Max = -1;

        for(int j = 1; j <= 100005; j++)
        {
            Max = max(Max , t[i]);
        }

        cnt = Max;

        dfs(step - 1 , cnt , n , m);

        energy[i] - 1;
    }


}

int main()
{

    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);

	int n , m;

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
	    cin >> energy[i];
	}

	int Max_result = -1;

	for(int i = 1; i <= m; i++)
    {
        int result = dfs(0 , 0 , n , i);
        Max_result = max(Max_result , result);
    }

    cout << Max_result << endl;







	return 0;

}
