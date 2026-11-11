#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int now[500005];
int pos[500005];
int end_pos=1;
int ans[500005];
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
        memset(pos,-1,sizeof pos);
        end_pos=1;
        for(int j=i;j<=n;j++){
            if(pos[a[j]]==-1||pos[a[j]]>=end_pos){
                if(pos[now[end_pos]]==end_pos){
                    pos[now[end_pos]]=-1;
                }
                now[end_pos++]=a[j];
                pos[a[j]]=end_pos-1;
            }else{
                end_pos=pos[a[j]]+1;
            }
        }
        for(int k=1;k<end_pos;k++){
            ans[now[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
