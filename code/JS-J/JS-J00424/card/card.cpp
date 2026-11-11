#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[200005];
bool b[200005];
int res[200005];
int res_[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,false,sizeof(b));
        memset(res,0,sizeof(res));
        memset(res_,0,sizeof(res_));
        int x=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                x=res_[a[j]];
            }
            else{
                b[a[j]]=true;
                x++;
                res[x]=a[j];
                res_[a[j]]=j;
            }
        }
        for(int j=1;j<=x;j++){
            ans[res[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
