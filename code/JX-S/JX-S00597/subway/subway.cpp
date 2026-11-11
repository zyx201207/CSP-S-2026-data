#include<bits/stdc++.h>
using namespace std;
int w[500010];
int k[500010];
int a[510][500010];
int t[510][500010];
int e,f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=q;i++){
        cin>>e>>f;
        ans=0;
        for(int j=e;j<=f;j++){
            if(j==e){
                ans+=w[j];
            }if(j==f){
                ans+=t[f-1][f];
                ans+=w[j];
            }
            else{
                int cnt=1;
                for(int k=cnt;k<=j;k++){
                    ans+=t[k][j];
                }
                cnt=j;
            }
        }cout<<ans<<endl;
    }
    return 0;
}
