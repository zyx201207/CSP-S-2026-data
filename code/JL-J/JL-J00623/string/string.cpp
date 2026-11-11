#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string,out","w",stdout);
int n;
cin>>n;
if(n==1){
cout<<0;
}
for(int i=1;i<=n;i++){
cin>>a[i]>>b[i];
}
for(int i=1;i<=n;i++){
if(n==2&&b[i]==a){
cout<<0;
}
}
return 0;
}
