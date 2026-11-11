#include<bits/stdc++.h>
using namespace std;
int a[5010],b[3010][5010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=i;j<=n;j++){
            for(int h=1;h<=cnt;h++){
                if(b[h][i]==a[j]){
                    for(int k=h;k<=cnt;k++){
                        b[k][i]=0;
                    }
                    cnt=0;
                }
            }
            cnt++;
            b[cnt][i]=a[j];
        }
    }
    for(int i=1;i<=m;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int h=1;;h++){
                if(b[h][j]==0) break;
                if(b[h][j]==i){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<" ";
    }
}
