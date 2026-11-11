#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	for(int i=1;i<=n/2;i++){
		cout<<g[i]<<endl;
	}
	return 0;
}
