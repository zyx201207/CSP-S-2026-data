#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,maxm=3e5+10;
int n,m,a[maxn],last[maxm],p[maxm],t[maxn],ans[maxm],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	
	
	
	
	return 0;
} 
