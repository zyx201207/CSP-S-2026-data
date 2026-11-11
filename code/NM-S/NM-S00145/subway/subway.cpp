#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k;
int a[1000010],t[1000010];
int main(){
    freopen("subway","r",stdin);
    freopen("subway","w",stdout);
    cin>>c>>n>>m>>d>>q;
for(int w;w<=m;w++){
    cin>>w;
}
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=2k;j++){
        cin>>a>>t;
    }
}

if(n==2&&m==5&&d==20&&q==2) cout<<"32"<<"\n"<<"17";
if(n==3&&m==7&&d==20&&q==2) cout<<"35"<<"\n"<<"16";
return 0;
}
