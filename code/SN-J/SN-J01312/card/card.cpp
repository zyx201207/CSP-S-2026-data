#include<bits/stdc++.h>
using namespace std;
freopen(card.in,"r",stdin); 
freopen(card.out,"w",stdout);
int main()
{
	 int a,s;
	 cin>>a>>s;
	 int d[a+5],f[a+5],g[s+5];
	 for(int i=0;i<a;i++){
	 	cin>>d[i];
	 }
	 for(int i=0;i<a;i++){
	 	for(int j=0;j<a;j++){
		 	if(f[j]==d[i]){
		 		for(int k=j;k<a;k++){
		 			f[k]=0;
				}
				f[j]=d[i];
			}
		}
		for(int j=0;j<a;i++) {
			if(f[j]==j+1){
				g[j]+=1;
				f[j]=0;
			}
		}
	 }
	 for(int i=0;i<s;i++){
	 	cout<<g[i];
	 }
	return 0;
 } 
