#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,sum=-1,x[200005];
void dfs(int y,int k){
    if(y==m+1){
        long long v=x[1];
        for(int i=2;i<=m;i++){
            v=v&x[i];
        }
        if(v>sum){
            sum=v;
        }
        return;
    }
    for(int i=k+1;i<=n;i++){
        x[y]=a[i];
        dfs(y+1,i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==n){
       for(int i=1;i<=n;i++){
            cin>>a[i];
            if(sum==-1){
                sum=a[i];
            }
            else{
                sum=sum&a[i];
            }
        }
         cout<<sum;
         return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>sum){
                sum=a[i];
            }
        }
         cout<<sum;
         return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0);
    cout<<sum;
    return 0;
}
