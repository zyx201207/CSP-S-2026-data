#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]; 
	for(int i=1;i<=m;i++)
		cout<<a[1]<<a[2]<<a[3];
	return 0;
}
