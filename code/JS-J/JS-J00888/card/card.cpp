#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long int n,m,bi,ansi;
long long int a[N];
long long int ans[N],b[N];
long long int cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        bi=1;
        for(int j=i;j<=n;j++){
            b[bi]=a[j];
            bi++;
        }
        bi--;
        ansi=1;
        for(int j=1;j<=n;j++){
            int gay=-1;
            for(int k=j+1;k<=n;k++){
                if(b[j]==b[k]){
                    gay=k;
                }
            }
            if(gay==-1){
                ans[ansi]=b[j];
                ansi++;
            }else{
                j=gay;
                ans[ansi]=b[j];
                ansi++;
            }
        }
        for(int j=1;j<=m;j++){
            for(int k=1;k<ansi;k++){
                if(ans[k]==j){
                    cnt[j]++;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
