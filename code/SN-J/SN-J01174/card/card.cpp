#include<bits/stdc++.h>
using namespace std;
int a[i];
int main(){
	freopen("card.in","r",stdin);
	freopen("caed.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==j)
			int cnt=0;
			cnt++;
		}
		a[i]=a[i]+cnt;
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
