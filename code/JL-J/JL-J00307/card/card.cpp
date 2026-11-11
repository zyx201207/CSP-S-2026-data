#include<bits/stdc++.h>
using namespace std;
long long n,m,a[530000];
long long b[500003],c[500004];
void dif(int x,int y){//xjiju,yjige
    if(x>n){
        return;
    }
    for(int j=1;j<=y;j++){
        if(b[j]==a[y]){
            for(int k=j;k<=y;k++){
                b[k]=0;
            }
            b[j]=a[x];
            dif(x,j+1);
        }
    }
    b[y]=a[x];
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    dif(x+1,y+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
             b[i]=0;
       }
       dif(i,1);
       for(int j=1;j<=n;j++){
            c[b[i]]++;
       }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
