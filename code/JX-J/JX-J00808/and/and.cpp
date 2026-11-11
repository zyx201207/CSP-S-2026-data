#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN=2e5+1,INF=0x3f3f3f3f;
using ll=long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[MAXN]={};
    bool d[MAXN]={};
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        int s=0;
        for(int j=1;j<=n;j++){
            if(d[j]==1)continue;
            if(((a[j]>>i)&1)==1)s++;
        }
        if(s>=m){
            for(int j=1;j<=n;j++){
                if(d[j]==1)continue;
                if(((a[j]>>i)&1)==0){
                    d[j]=1;
                }
            }
            ans+=1<<i;
        }
    }
    cout<<ans;
}
