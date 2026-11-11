#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int lst[N];
int nxt[N];
int ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lst[a[i]]!=0)nxt[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x=i;
		while(x<=n){
			while(nxt[x]!=0)x=nxt[x];
			ans[a[x]]++;
			x++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}