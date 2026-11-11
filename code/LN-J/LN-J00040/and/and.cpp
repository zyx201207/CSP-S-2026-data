#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
int n,m,ma=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
}
int x;
if(m==2){
    for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
        x=a[i]&a[j];
        ma=max(ma,x);
    }
}
cout<<ma;
}

return 0;
}
