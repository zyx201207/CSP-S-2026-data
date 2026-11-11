#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]!=a[i-1])  b[j]++;
		}
	}
	for(int i=m;i>=1;i--)  cout<<b[i]<<" ";
	return 0;
}