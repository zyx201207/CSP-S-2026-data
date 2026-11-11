#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[500005],temp[300005],pos[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        x=0;
        memset(temp,0,sizeof(temp));
        memset(pos,255,sizeof(pos));
        for(int j=i;j<n;j++){
            if(~pos[a[j]]){
                for(int k=pos[a[j]]+1;k<x;k++){
                    pos[temp[k]]=-1;
                }
                x=pos[a[j]]+1;
            }else{
                temp[x]=a[j];
                pos[a[j]]=x;
                x++;
            }
        }
        for(int j=1;j<=m;j++){
            if(~pos[j]){
                ++ans[j];
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << ' ';
    }
}
