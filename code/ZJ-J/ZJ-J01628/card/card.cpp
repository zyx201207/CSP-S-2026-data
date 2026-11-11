#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int a[N],las[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		las[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int p=i;
		while(p<=n){
			p=las[a[p]];
			ans[a[p]]++;
			p++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
