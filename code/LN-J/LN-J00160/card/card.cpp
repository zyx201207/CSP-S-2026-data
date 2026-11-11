#include<bits/stdc++.h>
using namespace;
int z[500005],cnt[300005],cny[500005];
int main(){
    freedom("card.in",stdin.in);
    freedom("card.out",stdout.out);
    int n,m;cin>n>>m;
    for(int i=1;i<=n;i++){
        cin>>z[i];
    }
    for(int i=1;i<=n;i++){
    for(int r=1;r<=n;r++)cny[r]=0;
        for(int j=i;j<=n;j++){
            if(j==1){
                cny[1]=z[i];
                continue;
            }
            if(!cny.find(z[j]))cny[j]=z[j];
            else{
                for(int q=j+1;q<=n;q++){
                    cny[q]=0;
                }
            }
        }
        for(int l=1;l<=n;l++)cnt[cny(l)]++;
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[i];
    }
}
