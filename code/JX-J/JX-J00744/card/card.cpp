#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
const int N=5e5+10;
LL a[N];
bool vis[N];
bool c_t[N];
LL c[N];
int main(){
    IOS;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    for(LL i=n;i>=1;i--){
        if(c[a[i]]<=0) c[a[i]]=i;
        if(vis[a[i]]){
            LL end_a=0;
            for(LL j=i+1;j<=n;j++){
                if(a[j]==a[i]){
                    end_a=j;
                    break;
                }
            }
            for(LL j=i+1;j<end_a;j++){
                if(a[j]==a[i]) break;
                if(!c_t[a[j]]&&c[a[j]]>end_a) continue;
                if(!c_t[a[j]]) c[a[j]]=0;
                c[a[j]]=max(c[a[j]],j-i);
                c_t[a[j]]=1;
            }
        }
        vis[a[i]]=1;
    }
    for(LL i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
