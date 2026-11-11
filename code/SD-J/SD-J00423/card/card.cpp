#include<bits/stdc++.h>
using namespace std;
int a[500005];
int shu[500005]={0};
int daan[500005]={-1};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}	
	int cnt=0;
	int p=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(shu[a[j]]==0){
				shu[a[j]]=p++;
				daan[cnt++]=a[j];
			}
			else{
				for(int k=shu[j];k<=j;k++){
					daan[shu[j]]=-1;
				}
			}
			
		}
	}
	for(int i=1;i<=cnt;i++){
		if(daan[i]!=-1){
			cout<<daan[i]<<" ";
		}
	}
	return 0;
} 
