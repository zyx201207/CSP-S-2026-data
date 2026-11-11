#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[500005];
int t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int tab[300005]={};
		for(int j=i;j<=n;j++){
			if(tab[a[j]]==1)
				continue;
			t[a[j]]++;
			tab[a[j]]=1;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<t[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
