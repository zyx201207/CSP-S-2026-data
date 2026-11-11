#include<bits/stdc++.h>
using namespace std;
int a[500005],ha[300005],game[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int top=0;memset(ha,0,sizeof(ha));
        memset(game,0,sizeof(game));
        for(int j=i;j<=n;j++){
            if(ha[a[j]]&&ha[a[j]]<=top&&a[j]==game[ha[a[j]]]){
                top=ha[a[j]];
            }else{
                game[++top]=a[j];
                ha[a[j]]=top;
            }
        }
        for(int j=1;j<=top;j++)ans[game[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
