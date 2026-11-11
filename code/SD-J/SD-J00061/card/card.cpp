#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x;
		a[x]=max(a[x],i);
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
} 
