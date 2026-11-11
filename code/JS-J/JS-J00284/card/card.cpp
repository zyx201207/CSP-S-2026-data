#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int mn[N],n,m,a[N],ans[300005];
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
    int p=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<p;k++){
                if(mn[k]==a[j]){
                    for(int l=k;l<p;l++){
                        mn[l]=0;
                        p--;
                    }
                    p--;
                }
            }
            mn[p]=a[j];
            p++;
        }
        for(int j=1;j<p;j++){
            ans[mn[j]]++;
        }
        memset(mn,0,sizeof(mn));
    }
    cout<<'\n';
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
