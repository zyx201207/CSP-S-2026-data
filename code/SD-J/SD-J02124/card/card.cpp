#include<bits\stdc++.h>
using namespace std;
long long js[200005];
int a[200005];
int zhan[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int r=1;
			for(int j=i;j<=n;j++){
				zhan[r]=a[j];
				for(int k=1;k<r;k++){
					if(zhan[k]==a[j]){
						r=k;
					}
				}
				r++;
			} 
			for(int j=1;j<=r-1;j++){
				js[zhan[j]]++;
			}
		} 
		for(int i=1;i<=m;i++){
			cout<<js[i]<<' ';
		}
	} 
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			js[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			js[i]+=js[i-1];
			cout<<js[i]<<' ';
		}
	} 
	return 0;
}
