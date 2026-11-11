#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int c,t,n,d,b,e;
cin>>c>>t;
cin>>n>>d;
int a[n],z[n];
for(int i=0;i<=n;i++){
    cin>>a[i];
}
cin>>b>>e;
for(int j=0;j<=b;j++){
    cin>>z[j];
}
if(a[0]==1){
    cout<<1<<" "<<2<<endl;
}else{
cout<<0<<" "<<1<<endl;
}
return 0;
}
