#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,mx,r;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        r=a[i]&a[i+1];
    }
    if(r>mx){
        mx=r;
    }
}
cout<<mx;
fclose(stdin);
fclose(stdout);
return 0;
}
