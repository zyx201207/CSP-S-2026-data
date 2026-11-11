#include<bits/stdc++.h>
using namespace std;
int n,m=0,i,j,k=0;
string b="";
struct q{
	int sum;
	char z;
	};
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
q a[n+1];
for(i=1;i<=n;i++){
cin>>a[i].sum>>a[i].z;
m+=a[i].sum;
for(j=1;j<=a[i].sum;j++)
b+=a[i].z;
}
for(i=0;i<m/2;i++){
if(b[i]!=b[m-i-1]);
k++;
}
cout<<k;
return 0;
}
