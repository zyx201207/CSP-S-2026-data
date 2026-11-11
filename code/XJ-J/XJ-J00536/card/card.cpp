#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int pos[300010];
int ans[300010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		pos[x]++;
	}
	for(int i=0;i<m;i++) {
		cout<<pos[i]<<" ";
	}
	
	
	
	
	
	return 0;
}