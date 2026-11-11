#include<bits/stdc++.h>
using namespace std;
int b[300000],bb[300000];
bool bol[300000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n];
for(int i=0;i<n;i++){
cin>>a[i];	
}
for(int j=0;j<n;j++){

for(int i=j;i<n;i++){
	b[a[i]]++;
	if(b[a[i]]==2){
		b[a[i]]=1;
		int ij=i-1;
		while(a[ij]!=a[i]){
			bol[ij]=1;
			ij--;
		}
		bol[ij]=1;
	}
	
}
for(int i=j;i<n;i++){
	if(bol[i]==0)
	  bb[a[i]]++;
	bol[i]=0;
}
}
for(int i=0;i<m;i++)
 cout<<bb[a[i]]<<' ';
	 return 0;
}