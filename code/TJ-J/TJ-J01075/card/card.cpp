#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(card.in,"r",stdin);
	freopen(card.out,"w",stdout);
	int n,m,a[100000],b[100000],ans=0,k=0,x[100000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
{
	cin>>a[i];
}for(int i=0;i<n;i++){
	
	k=1;
	b[0]=a[0];
	for(int h=1;i<n;h++){
	
	    for(int j=0;j<k;j++){
		    if(b[j]=a[h]){
			for(int u=j;j<i;j++){
				b[u]=0;
			}b[j]=a[h];
			k=j;
		}else{
			k++;
		}
	}}for(int l=1;l<=m;l++){
		for(int p=0;p<k;p++){
			if(b[p]==l){
				x[i]+=1;
			}
		}
	}for(int v=0;v<=k;v++){
		b[v]=0;
	}
}for(int i=0;i<m;i++){
	cout<<x[i]<<' ';
}return 0;
}
