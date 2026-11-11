#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005],p[100005],cnt[100005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int game=1;
    while(game<=n){
        memset(p,0,sizeof(p));
        int s=0;
        for(int i=game;i<=n;i++){
            p[s+1]=a[i];s++;
            for(int j=1;j<s;j++){
                if(p[j]==p[s]){
                    p[j]=p[s];
                    for(int k=j+1;k<=s;k++)p[k]=0;
                    s=s-(s-1)+j-1;
                }
            }
        }
        for(int i=1;i<=s;i++)cnt[p[i]]++;
        game++;
    }

    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
