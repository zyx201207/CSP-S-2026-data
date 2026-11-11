#include<bits/stdc++.h>
using namespace std;
int a[500010],ji[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ji[j[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ji[i];
	return 0;
}
