#include<bits/stdc++.h>
using namespace std;
int n,M;
long long a[500010],b[500010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>M;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=M;i++){
		cout<<i<<" ";
	}
	return 0;
}
