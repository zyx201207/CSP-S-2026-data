#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,c=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i+1]>a[i])  c=a[i+1];
}
if(m==1){
    cout<<c;
}
return 0;
}

