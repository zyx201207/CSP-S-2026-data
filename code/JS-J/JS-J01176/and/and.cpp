#include<bits/stdc++.h>
using namespace std;
 int main(int argc, char const *argv[])
 {
 	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	int n, m;
 	cin >> n >> m;
 	int a[n];
 	int mark[n];
 	int num = 0;
 	int ans, maxans=0;
 	for (int i = 0; i < n; ++i)cin >> a[i];
 	do{

 		for (int i = 0; i < n; ++i)
 		{
 			mark[i] = 0;
 		}
 		for (int q = n-1; q > n-1-m; --q)
 		{
 			mark[q]=1;
 		}
		for (int i = 0; i < m; ++i)
		{
			if (mark[i]==1)num = num*10+a[i];
		}
		ans = num;
		maxans = ans > maxans?ans:maxans;
 	}while(next_permutation(mark, mark+m));
 	cout << maxans;
 	return 0;
 }