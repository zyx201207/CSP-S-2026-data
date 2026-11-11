#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005]={},b[500005]={},ton[300005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i,k=1;j<=n;j++,k++){
			bool f=0;
			int t;
			for(int l=1;l<=k;l++){
				t=l;
				if(b[l]==a[j]){
					f=1;
					break;
				}
			}
			if(f){
				k=t;
			}
			b[k]=a[j];
		}
		for(int j=1;j<=m;j++){
			ton[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ton[i];
	}
	return 0;
}
