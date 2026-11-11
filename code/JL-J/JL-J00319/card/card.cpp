#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[10];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >>n >>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    b[1]=a[1];
    c[a[1]]++;
    int bl=1;
    for(int q=1;q<=n;q++){
    for(int y=q;y<=n;y++){
    int al=y+1;
    for(int i=1;i<=bl;i++){
    if(a[al]==b[i]){
        for(int j=i+1;j<=bl;j++){
            b[j]=0;
            bl--;
        }
    }
    else{
            bl++;
        b[bl]=a[al];
        al++;

    }
    }
            }
            for(int j=1;j<=bl;j++){
            c[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << c[i]<<" ";
    }
return 0;
}
