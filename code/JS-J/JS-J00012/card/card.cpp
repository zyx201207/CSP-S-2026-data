#include<bits/stdc++.h>
using namespace std;
int n,a[1919810],m,t[1919810],cn,ans[114514];
bool b[114514];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]; }
        for(int i=1;i<=n;i++){
              cn=0;
            memset(b,0,sizeof(b));

                for(int j=i;j<=n;j++){
                        if(1){
            for(int k=1;k<=cn;k++){
                if(b[k]==1 && t[k]==a[j]){
                    for(int l=k;l<=cn;l++){
                        b[l]=0;
                    }
                    break;
                }
            } }
            cn++,b[cn]=1,t[cn]=a[j];
                }
                for(int j=1;j<=cn;j++){
                    if(b[j]==1) ans[t[j]]++;
                }


        }

        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";}
     return 0;}


