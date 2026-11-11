#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],b[200020][2],c[200020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			c[a[i-1]]=i-1;
		}
	}
	c[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
