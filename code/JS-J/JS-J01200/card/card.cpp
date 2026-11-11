#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int las[300005];
int nex[300005];
int a[500005];
int s[5005][3005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        nex[i]=n+1;
    }
    for(int i=1;i<=n;i++){
        if(las[a[i]]){
            nex[las[a[i]]]=i;
        }
        las[a[i]]=i;
    }
    s[n][a[n]]=1;
    for(int i=n-1;i>=1;i--){
        if(nex[i]==n+1){
            for(int j=1;j<=m;j++)s[i][j]=s[i+1][j];
            s[i][a[i]]++;
        }
        else{
            for(int j=1;j<=m;j++)s[i][j]=s[nex[i]][j];
        }
    }
    int ans=0;
    //for(int i=1;i<=n;i++)cout<<nex[i]<<" ";
    for(int i=1;i<=m;i++){
        ans=0;
        for(int j=1;j<=n;j++)ans+=s[j][i];
        cout<<ans<<" ";
    }
    return 0;
}
