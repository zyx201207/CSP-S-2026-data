#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a[k]++;
	}
	long long di=0;
	for(int i=1;i<=m;i++){
		cout<<a[i]+di<<' ';
		di+=a[i];
	}
	
	return 0;
} 
