/*
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int ans[N];
int idxx[N];
map<int,int>mp;
int main(){
    freopen("/home/user/Desktop/card/card6.in","r",stdin);
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        idxx[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int idx=i;
        while(idx<n){
            idx=idxx[a[idx]];
            ans[a[idx]]++;
            idx++;
        }
        ans[a[idx]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int ans[N];
int dp[N];
int pre[N];
int idxx[N];
int initpre[N];
int cnt[N];
int main(){
    //freopen("/home/user/Desktop/card/card6.in","r",stdin);
    //freopen("/home/user/Desktop/card/card6.out","w",stdout);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(initpre[a[i]])pre[i]=initpre[a[i]];
        initpre[a[i]]=i;
        idxx[a[i]]=i;
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<pre[i]<<" ";
    }
    cout<<"\n";
    */
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]*(idxx[a[i-1]]==i-1)+dp[pre[i]]+cnt[a[i]]*(idxx[a[i]]==i);
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    */
    for(int i=1;i<=n;i++){
        if(idxx[a[i]]!=i)continue;
        ans[a[i]]+=dp[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}





