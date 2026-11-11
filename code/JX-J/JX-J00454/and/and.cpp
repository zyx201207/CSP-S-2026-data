#include<iostream>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int m,n,a[100],b[100000],z=1,q=-1;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(m==2){
    for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        b[z]=(a[i] & a[j]);
        z++;
    }
}
}
if(m==3){
    for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
            for(int v=j;v<=n;v++){
                b[z]=(a[i] & a[j] & a[v]);
        z++;
            }

    }
}
}
for(int i=1;i<=z-1;i++){
    if(b[i]>q){
        q=b[i];
    }
}
cout<<q;
return 0;
}
