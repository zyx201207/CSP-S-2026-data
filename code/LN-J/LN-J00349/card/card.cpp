#include<bits/stdc++.h>
using namespace std;
bool op[300005];
int crd[500005],desk[500005],ans[300005],cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>crd[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!op[crd[j]]){
                cnt++;
                desk[cnt]=crd[j];
                op[crd[j]]=true;
            }
            else{
                for(int k=1;k<=cnt;k++){
                    if(desk[k]==crd[j]){
                        int old=cnt;
                        for(int l=k;l<=old;l++){
                            cnt--;
                            op[desk[l]]=false;
                            desk[l]=-1;
                        }
                        cnt++;
                        desk[cnt]=crd[j];
                        op[crd[j]]=true;
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(op[j]) ans[j]++;
            op[j]=false;
        }for(int j=1;j<=n;j++){
            desk[j]=-1;
        }
        cnt=0;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
