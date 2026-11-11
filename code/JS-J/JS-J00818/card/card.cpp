#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int pl[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int _=1;
    while(_<=n){
        int c=1;
        for(int i=_;i<=n;i++){
            for(int j=1;j<=c;j++){
                if(pl[j]==a[i]){
                    c=j;
                }
            }
            pl[c]=a[i];
            c++;
        }
        for(int i=1;i<c;i++){
            ans[pl[i]]++;
        }
        _++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
