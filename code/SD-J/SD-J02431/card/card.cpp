#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int a[500005];
stack<int> b;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	vector<int> c(m,0);
	int c1[m]={};
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b.empty()) {
				b.push(a[j]);
				c1[a[j]]++;
			}
			else{
				if(c1[a[j]]!=0){
					b.push(a[j]);
					c1[a[j]]++;
				}
				else{
					int bb=b.top();
					while(bb!=a[j]){
						
						b.pop();
						bb=b.top();
					}
				}
			}
		}
		while(!b.empty()){
			c[b.top()]++;
			b.pop();
		}
		
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
