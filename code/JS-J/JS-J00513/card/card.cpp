#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
bool f[300010];
int q[100010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        memset(q,0,sizeof(q));
        int w=0;
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                w++;
                q[w]=a[j];
                f[a[j]]=1;
            }else{
                while(q[w]!=a[j]){
                    w--;
                }
            }
        }
        while(w>0){
            ans[q[w]]++;
            w--;
         }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/