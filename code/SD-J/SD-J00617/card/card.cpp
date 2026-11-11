#include <bits/stdc++.h>
using namespace std;
int a[500005], b[300005], c[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}
	else{
		int f=1;
		for(int i=1;i<=m;i++){
			int p=1;
			while(a[p]<=i&&p<=n){
				c[p]++;
				p++;
			}
		} 
		for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
	}
	return 0;
} 
