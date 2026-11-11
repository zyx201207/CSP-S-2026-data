#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005]={},cnt,box[500005]={};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		int d[500005]={};
		for(int j=i;j<=n;j++){
			d[++cnt]=a[j];
			for(int k=1;k<cnt;k++){
				if(d[k]==d[cnt]){
					for(int c=k;c<cnt;c++){
						d[c]=0;
					}
					d[k]=d[cnt];
					cnt=k;
				}
			}
		}
		for(int j=1;j<=cnt;j++){
			box[d[j]]++;
		}
	}
	for(int i=1;i<=500005;i++){
		if(box[i]>0){
			cout<<box[i]<<" ";
		}
	}
	return 0;
}
