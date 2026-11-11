#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c,e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=0;x<n;x++){
		e=1;
		for(int i=1;i<=n-x;i++){
			for(int j=1;j<=n-x;j++){
				if(a[i]==a[j]&&i!=j){
					i=j;
					e=i;
				}
			}
		}
		for(int i=e;i<=n-x;i++){
			for(int j=1;j<=m;j++){
				if(j==a[i]) b[j]++;
			}
		}
		for(int i=1;i<n-x;i++){
			a[i]=a[i+1];
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
}