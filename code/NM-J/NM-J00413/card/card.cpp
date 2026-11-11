#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
   int n,m,a[10000],b[10000];
   int s1=0,s2=0,s3=0;
   cin>>n>>m;
   	for(int i=0;i<n;i++){
   		cin>>a[i];
   }
   int k=0;
   for(int i=0;i<n;i++){
   		b[k]=a[i];k++;
   		if(a[i]==1){
   			s1++;
		}
		if(a[i]==3){
   			s2++;
		}
		if(a[i]==3){
   			s3++;
		}
   		if(a[i]<=a[i-1]){
   			k=0;
   			b[k]=a[i];
   			if(a[i]==1){
   			s1++;
		}
		if(a[i]==3){
   			s2++;
		}
		if(a[i]==3){
   			s3++;
		}
		}
   }
   cout<<s1<<" "<<s2<<" "<<s3;
    return 0;
}
