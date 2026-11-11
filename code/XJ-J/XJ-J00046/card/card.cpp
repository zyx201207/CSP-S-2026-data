#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50010],b[10010],fb[10010],ls[50010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int j=1;j<=m;j++){
		cout<<b[j]<<' ';
	}
	return 0;
}
