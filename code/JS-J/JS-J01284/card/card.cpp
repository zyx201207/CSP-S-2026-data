#include<bits/stdc++.h>
using namespace std;
struct node{
    int no[1145140];
};
int n,m,a[1145140],maxn,vis[1145140],p[1145140];
node v[1145140];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(p,0,sizeof(p));
        int x=0;
        for(int j=i;j<=n;j++){
            x=j+1-i;
            if(vis[a[j]]){
                for(int l=j+1-i;l>0;l--){
                    if(p[l]==a[j]){
                        break;
                    }
                    p[l]=0;
                    x--;
                }
            }
            p[++x]=a[j];
            vis[a[j]]=1;
        }
        for(int j=1;j<=x;j++){
            v[i].no[j]=p[j];
        }
    }
    for(int i=1;i<=n;i++){
        int g=0,j=0;
        for(int l=1;l<=n;l++){
            while(v[l].no[++j]){
                if(v[l].no[j]==i){
                    g++;
                    break;
                }
            }
        }
        cout<<g<<' ';
    }
    return 0;
}
//please help me RP++
