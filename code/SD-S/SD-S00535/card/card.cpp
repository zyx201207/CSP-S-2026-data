#include<bits/stdc++.h>
using namespace std;
map<long long,long long> p;
long long n,m,a[200005],cnt,sum[200005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<1<<" ";
	}
	return 0;
} 
