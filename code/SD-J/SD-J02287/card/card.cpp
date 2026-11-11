#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10000000],ans[10000000],b[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		for(int j=1;j<=m;j++){
			if(a[i]==j)
			ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
//4 3 1 2 1 3
//10 3 3 1 2 1 3 2 3 1 2 1
