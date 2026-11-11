#include<bits/stdc++.h>
using namespace std;
int a[78911145];
int b[78911145];
int d[78911145];
int main(){
	int n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]==0){
			b[a[i]]=i;
		}
		for(int j=i;j<=n;j++){
			d[a[j]]++;
			if(b[a[j]]!=0){
				j=b[a[j]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
