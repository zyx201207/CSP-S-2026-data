#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],f[300005],p[500005];	
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		int t=0;
		for(int j=i;j<n;j++){
			for(int k=0;k<n-i+1;k++){
				if(p[k]==a[j])t=k+1;
			}
			p[t]=a[j];
			t++;
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<=t;j++){
				if(p[j]==i)f[i]++;
				break;
			}
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	} 
	return 0;
}
