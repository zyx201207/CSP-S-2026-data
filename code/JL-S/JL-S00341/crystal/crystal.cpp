#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crytal.in","r",stdin);
freopen("crytal.out","w",stdout);
int n,a[10001],b=0;
long long m;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
}
for(int i=1;i<=n;i++){
for(int j=1;j<=i;j++){
 if(a[i]>a[j])
 b=a[i];
 a[i]=a[j];
 a[j]=b;
}
}
for(int i=1;i<=3;i++){
cout<<a[i];
}
return 0;
}
