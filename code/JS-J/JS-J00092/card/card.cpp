#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5+5,M = 3e5+5;
int n,m,a[N],vis[N],box[N],ans[N];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		memset(box,0,sizeof box);

		int right = 1;
		for(int j=i;j<=n;j++)
		{
			// a[j]
			if(!vis[a[j]]) {
				vis[a[j]] = right;
				box[right] = a[j];
				right ++;
			}
			else 
			{
				right = vis[a[j]] + 1;
			}
		}
		for(int j=1;j<right;j++) ans[box[j]] ++ ;
	}

	for(int i=1;i<=m;i++) cout << ans[i] << ' ';

	return 0;
}
