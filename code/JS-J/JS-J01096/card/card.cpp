#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N],ans[M];
void getans(int l){
     int ct[M];
     memset(ct,0,sizeof(ct));
     for(int i=l;i<=n;i++){
        if(ct[a[i]]!=1)ct[a[i]]++;
        else{
            int j=i-1;
            while(a[j]!=a[i]){
                ct[a[j]]--;
                j--;
            }
            ct[a[i]]=1;
        }
     }
     for(int i=1;i<=m;i++){
        ans[i]+=ct[i];
     }
     return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=n;l>=1;l--){
        getans(l);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N],ans[M];
string dp[N];
void getans(int l){
     int ct[M];
     memset(ct,0,sizeof(ct));
     for(int i=l;i<=n;i++){
        if(ct[a[i]]==1){
            for(int j=1;j<=m;j++){
                ans[j]+=int(dp[a[i]][j]);
            }
        }
        else ct[a[i]]++;
     }
     for(int i=1;i<=m;i++){
        ans[i]+=ct[i];
        dp[l]+=char(ct[i]);
     }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=n;l>=1;l--){
        getans(l);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}*/

