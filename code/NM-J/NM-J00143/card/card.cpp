#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k[n+5]={0};
    int w[n+5]={0};
    for(int i=1;i<=n;i++)
        cin>>k[i];
    for(int i=1;i<=n;i++){
        int r[n+5]={0};
        for(int j=i;j<=n;j++)
            if(r[j]==0)
                w[k[j]]++;}
    for(int i=1;i<=m;i++)
        cout<<w[i]<<' ';
    return 0;
}
