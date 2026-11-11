#include<bits/stdc++.h>
using namespace std;
int a[10001];
int b[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<m<<" ";
	}
	return 0;
} 
