#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string","r",stdin);
freopen("string","w",stdout);
int n,a[1000000000],k=1,z=1,num=0;
cin>>n;
char q[1000000000],p[1000000000],b[1000000000];
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
for(int j=1;i<=a[1];j++){
	q[k]=b[i];
	k++;
}
}
for(int i=k;i>=1;i--){
	p[z]=q[i];
}
for(int i=1;i<=k;i++){
if(p[i]!=q[i])
num++;
}
cout<<num;
}
