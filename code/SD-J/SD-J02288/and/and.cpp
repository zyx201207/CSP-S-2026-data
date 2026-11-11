#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=-1,abc;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++){
		abc = a[i];
		for(int j=i+1;j<=n;j++){
			for (int t=1;t<=m;t++){
				for (int c=1;c<=n;c++)
					abc = abc & a[j+c];
			}
				
		}
		maxx = max(abc, maxx);
	}
	cout << maxx <<endl;
	return 0;
}
