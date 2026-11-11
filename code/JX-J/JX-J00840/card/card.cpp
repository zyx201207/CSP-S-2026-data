#include <bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i];
        for(int j=1;j<i;j++){
            if(a[j]==a[i]){
                for(int k=i;k>=j;k--){
                    a[k]=0;
                }
            }
        }
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++){
        if(a[i]==0){
            continue;
        }
        if(a[i]==j){
            b[j]++;
        }
    }
    }
    for(int y=2;y<=n;y++){
      for(int i=y;i<=n;i++){
            a[i]=c[i];
        for(int j=y;j<i;j++){
            if(a[j]==a[i]){
                for(int k=i;k>=j;k--){
                    a[k]=0;
                }
            }
        }
      }
      sort(a+y,a+n+1,greater<int>());
       for(int i=1;i<=m;i++){
       for(int j=1;j<=m;j++){
        if(a[i]==0){
            continue;
        }
        if(a[i]==j){
            b[j]++;
        }
    }
    }
}
for(int i=1;i<=m;i++){
    cout<<b[i]<<" ";
}
return 0;
}
