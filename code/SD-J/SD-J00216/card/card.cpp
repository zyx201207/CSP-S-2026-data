#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[501100],b[501100];
int c[301010],e[301010],d[301010];
int main(){
 freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
	 cin>>n>>m;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 }
	 for(int i=1;i<=n;i++){
	 	int k=1;
	 	memset(b,0,sizeof(b));
	 	memset(c,0,sizeof(c));
	 	memset(d,0,sizeof(d));
	 	for(int j=i;j<=n;j++){
	 		if(c[a[j]]!=0)
	 		{
	 			b[c[a[j]]]=-1;
	 			for(int h=c[a[j]];h<=j;h++)
	 				c[h]=0;
	 			b[j]=1;
			 }
	 		d[k]=a[j];
	 		k++;
	 		c[a[j]]=j;
		 }
		 for(int j=i;j<=n;j++)
		 {
		 	if(b[j]==-1)
		 	{
		 		for(;j<=n;j++)
		 			if(b[j]==1)
		 				break; 
		 		e[d[j-i+1]]++;
			 }else
			 	e[d[j-i+1]]++;
		 }
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	cout<<e[i]<<" ";
	 }
	return 0;
} 
