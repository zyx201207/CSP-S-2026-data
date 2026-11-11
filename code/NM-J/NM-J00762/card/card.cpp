#include"bits/stdc++.h"
using namespace std;

const int N = 5 * 1e5 + 10;
const int M = 3 * 1e5 + 10;

int n , m;
int cad[N];
long long ans[M];

int main(){
	
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout); 
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> cad[i];
	
	
	for(int i = 1 ; i <= n ; i++) 
	{
		bool vis[N];
		memset(vis , false , sizeof(vis));

		stack<int> v;
		
		for(int j = i ; j <= n ; j++)
		{
			if(vis[cad[j]])
			{
				while(v.top() != cad[j] && !v.empty()) 
				{
					vis[v.top()] = false;
					v.pop();
				}
				v.pop();		
			}
			
			v.push(cad[j]);
			
			// cout << j << " "; 
			if(!vis[cad[j]]) vis[ cad[j] ] = true;
		}
		
		while(!v.empty())
		{
			//cout << v.top() << " ";
			ans[v.top()]++;
			v.pop();
		}
		
		// cout << endl;
		
		
	}
	
	for(int i = 1 ; i <= m ; i++) cout << ans[i] << " ";
	
	
	return 0;
}
