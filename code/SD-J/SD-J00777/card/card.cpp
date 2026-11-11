#include<bits/stdc++.h>
using namespace std;
int n,m,a[210100],b[301000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<' ';
	}
} 
