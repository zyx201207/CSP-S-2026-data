#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],v[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} int x=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			v[x]=i;
			x++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
} 
