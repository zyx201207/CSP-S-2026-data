#include<bits/stdc++.h>
using namespace std;
int a[200003],b[200003],c[200003],n,m,k=1;
void dfs(int x,int y){
    if(x==m+1){
        c[k]=b[1];
        for(int i=1;i<=m;i++){
            c[k]&=b[i];
        }
        k++;
        return ;
    }
    for(int j=1;j<=n&&j!=y;j++){
        b[x]=a[j];
        dfs(x+1,j);
        b[x]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0);
    sort(c+1,c+1+k);
    cout<<c[k];
    return 0;

}
