#include<bits/stdc++.h>
using namespace std;
int n,m,k,ren[500015];
int flag[300015];
int a[500005],fhz[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			
			if(flag[a[j]]==0){
				flag[a[j]]=j;
				ren[j-k]=a[j];
			}
			else{
				int pp=k;
				k+=j-flag[a[j]];
				for(int qw=j-k+1;qw<=j+10-pp;qw++){
					if(ren[qw]==a[j])break;
					flag[ren[qw]]=0;
					
				}
			}
			//cout<<flag[3]<<" ";
		}
		
			for(int qw=1;qw<=m;qw++){
				//cout<<flag[qw]<<" ";
				if(flag[qw]!=0){
					fhz[qw]++;
				}
				flag[qw]=0;
			}
			//cout<<endl;
		
	}
	for(int i=1;i<=m;i++)cout<<fhz[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
