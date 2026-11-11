#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={},sum[n+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cout<<sum[i]<<' ';
	}
	
	return 0;
}
