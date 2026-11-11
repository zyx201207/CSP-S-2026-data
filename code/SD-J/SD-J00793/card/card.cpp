#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10005],j=0;
	int ans[10005];
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	
		for(int i=0;i<n-1;i++){
			ans[j]++;
			if(a[i]!=a[i+1])
			{
				j++;
				ans[j]++;	
			}
		}
	for(int i=0;i<m;i++)
		cout << ans[i] << " ";
	return 0;
}
