#include<bits/stdc++.h>
using namespace std;
int a[500050],b[300050],n,m,v[500050];
void f(int x){
int z=1;
for(int i=x;i<=n;i++){
    for(int j=1;j<=z;j++){
        if(v[j]==a[i]){
            z=j;
        }
    }
    v[z]=a[i];
    z++;
}
for(int i=1;i<z;i++){
    b[v[i]]++;
    }
    return ;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    for(int i=1;i<=n;i++){
     f(i);
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
return 0;
}
