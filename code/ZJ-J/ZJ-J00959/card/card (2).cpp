#include<bits/stdc++.h>
using namespace std;
int n1[100000],n2[100000],n3[100000],n4[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>n1[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			n2[n1[j]]=n2[n1[j]]+1;
			if(n2[n1[j]]>1){
				for(int o=n3[n1[j]];o<=j;o++){
					n2[n1[o]]=0;
					n3[n1[o]]=0;
				}
				n2[n1[j]]=1;
				n3[n1[j]]=j;		
			}	
		}
		for(int j=1;j<=m;j++){
			n4[j]+=n2[j];
			n2[j]=0;
			n3[j]=0;	
		}
	}
	for(int j=1;j<=m;j++){
		cout<<n4[j]<<" ";	
	}
	return 0;
}



