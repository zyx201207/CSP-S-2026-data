#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

const int N = 5e5 + 5 , M = 3e5 + 5;

int a[N] = {0};
int vs[M] = {0};
int ans[M] = {0};

int n , m;

stack <int> slist;

int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	
	for(int i = 1;i <= n;++i)
	{
		for(int j = i;j <= n;++j)
		{
			if(vs[a[j]] == 1)
			{
				while(slist.top() != a[j])
				{
					vs[ slist.top() ] = 0;
					slist.pop();
				}
			}
			else
			{
				slist.push(a[j]);
				vs[a[j]] = 1;
			}
		}
		for(int i = 1;i <= m;++i)
		{
			ans[i] += vs[i];
		}
		
		
		memset(vs , 0 , sizeof(vs));
		
		while(!slist.empty())
		{
			slist.pop();
		}
		
	}
	
	for(int i = 1;i <= m;++i)
	{
		cout << ans[i] << " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
