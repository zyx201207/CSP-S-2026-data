#include<bits/stdc++.h>
using namespace std;
long long a[500500],vis[500500],b[300500];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,ans=0,len=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}for(int i=1;i<=n;i++){
		cout<<b[a[i]]<<" ";
	}
	return 0;
}
