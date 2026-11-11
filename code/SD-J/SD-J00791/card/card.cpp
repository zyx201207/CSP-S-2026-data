#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			if(a[j]==i)s++;
		}
		cout<<(s*i-a[i]+1)*2-2<<" ";
		s=0;
	}
	return 0;
} 
