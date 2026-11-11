#include<bits/stdc++.h>
using namespace std;
int n,m;
int nc[500005]={};
int mc[300005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>nc[i];
	for(int i=1;i<=n;i++){
		int jc[500005]={};
		for(int j=i;j<=n;j++){
			jc[j]=nc[j];
			for(int k=i;k<j;k++){
				if(jc[k]==jc[j]){
					for(int l=k;l<j;l++) jc[l]=0;
				}
			}
		}
		for(int o=1;o<=n;o++){
			if(jc[o]>0) mc[jc[o]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<mc[i]<<' ';
	return 0;
}
