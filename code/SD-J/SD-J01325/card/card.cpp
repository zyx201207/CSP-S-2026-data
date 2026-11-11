#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],y[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		y[a[i]]=i;
	}for(int i=1;i<=m;i++){
		cout<<y[i]<<' ';
	}
	return 0;
}

