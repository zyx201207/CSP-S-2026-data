#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],jilu[1000005];
int erfen(int l,int r,int x){
    while(l<r){
        int mid=(l+r+1)/2;
        if(b[mid]>x)r=mid-1;
        else l=mid;
    }
    return l;
}
void dfs(int x){
    memset(b,0,sizeof(b));
    int y=1;
    for(int i=x;i<=n;i++){
        int oo=erfen(1,y,a[i]);
        if(b[oo]!=a[i]){
            b[y]=a[i];
            sort(b+1,b+y);
            y+=1;
        }
        else if(b[oo]==a[i]){
            for(int j=oo;j<=y;j++){
                b[j]=0;
            }
            b[y]=a[i];
            y+=1;
        }
    }
    for(int i=1;i<=y;i++){
        jilu[b[i]]+=1;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    for(int i=1;i<=m;i++)cout<<jilu[i]<<" ";
    return 0;
}
