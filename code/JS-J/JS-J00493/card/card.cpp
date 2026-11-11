#include<bits/stdc++.h>
using namespace std;

#define int long long

int pai[300005],l,pl[500005];
bool f[500005];
int ans[500005];
int a[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) f[j]=pai[j]=pl[j]=0;
        l=0;

        for(int j=i;j<=n;j++){
            if(f[a[j]]){
                while(1){
                    if(pai[l]==a[j]) break;
                    f[pai[l]]=0;l--;
                }
            }
            else{
                f[a[j]]=1;
                pai[++l]=a[j];
            }
        }
        for(int j=1;j<=l;j++){
            ans[pai[j]]++;
           // cout<<pai[j]<<' ';
        }
       // cout<<'\n';

    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';

    return 0;
}


