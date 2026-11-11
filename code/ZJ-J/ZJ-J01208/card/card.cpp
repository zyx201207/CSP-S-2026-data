#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int b[N];
int sum[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int j=1;j<=n;j++){
		memset(b,0,sizeof b);
		stack<int>k;
		for (int i=j;i<=n;i++){
			if (!b[a[i]]){
				k.push(a[i]);
				b[a[i]]=1;
			}
			else {
				while (!k.empty() && k.top()!=a[i]){
					b[k.top()]=0;
					k.pop();
				}
			}
		}
		for (int i=1;i<=m;i++){
			if (b[i])sum[i]++;	
		}
	}
	for (int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0; 
} 
