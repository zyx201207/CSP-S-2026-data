#include<bits/stdc++.h>
using namespace std;
int a[500005],ha[300005],top=0;
int vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){ //ju
        for(int l=i;l<=n;l++){ //pi
            bool f=1;
            for(int j=1;j<=top;j++){
                if(ha[j]==a[l]){
                    for(int k=j+1;k<=top;k++) ha[k]=0;
                    top=j;
                    f=0;
                    break;
                }
            }
            if(f){
                top++;
                ha[top]=a[l];
            }
        }
        for(int x=i;x<=top;x++){
            vis[ha[x]]++;
            ha[x]=0;
        }
    }
    for(int i=1;i<=m;i++) cout<<vis[i]<<" ";
    return 0;
}
