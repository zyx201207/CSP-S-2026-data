// 蒲逸尘 西安理工大学附属中学 SN-J00669
#include <bits/stdc++.h>
using namespace std ;
int n , m , a[500005] ;
int ans[500005] , tong[500005] ;
int main()
{
	freopen("card.in" , "r" , stdin) ;
	freopen("card.out" , "w" , stdout) ;
	cin >> n >> m ;
	stack<int> st ;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] ;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = i ; j <= n ; j++)
		{
			tong[a[j]]++;
			if(tong[a[j]] > 1)
			{
				while(st.top() != a[j]) st.pop() ;
				if(st.top() == a[j]) st.pop() ;
			}
			st.push(a[j]) ;
		}
		while(!st.empty())
		{
			int cur = st.top() ;
			ans[cur]++ ;
			st.pop() ;
		}
		memset(tong , 0 , sizeof(tong)) ;
	}
	for(int i = 1 ; i <= m ; i++)
	{
		cout << ans[i] << " " ;
	}
	cout << endl ;
	return 0 ;
}
