#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001];
bool flag;
struct tx{
    int cnt;
    int k[200009];
    int l=1;
}f[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]].cnt++;
        f[a[i]].k[f[a[i]].cnt]=i;
    }
    for(int i=1;i<=n;i++){
        if(i>1){
            f[a[i-1]].l++;
        }
        flag=false;
        for(int j=i;j<=n;j++){
            int u=f[a[j]].k[f[a[j]].l];
            if(f[a[j]].k[++u]!=0){
                if(!flag) ans[a[j]]++;
                j=f[a[j]].k[++u]-1;
                flag=true;
            }
            else if(!flag){
                ans[a[j]]++;
                flag=true;
            }
        }
    }
    for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
    }
    return 0;
}
