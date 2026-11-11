#include<bits/stdc++.h>
using namespace std;
int n,m,cd[500005],cf[300005],pos[300005],qzh[500005],ans[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cd[i];
        pos[cd[i]]=i;
    }
    for(int i=n;i>=1;i--){
        if(pos[cd[i]]==i) cf[i]++;
        else cf[pos[cd[i]]]++;
    }
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+cf[i];
        if(i==pos[cd[i]]) ans[cd[i]]=qzh[i];
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
