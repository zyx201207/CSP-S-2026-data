#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e5+10;
vector<int> vt;
int eg,n,m,pp[M],a[N],ans[M],za2[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=1e4+1){
        for(int js=1;js<=n;js++){
            memset(pp,0,sizeof pp);
            for(int i=js;i<=n;i++){
                if(pp[a[i]]!=0){
                    eg=pp[a[i]]-1;
                    pp[a[i]]=i;
                }
                vt[eg+1]=a[i];
                eg++;
            }
            for(int i=1;i<=eg;i++){
                if(za2[vt[i-1]]!=js){
                    ans[vt[i-1]]++;
                    za2[vt[i-1]]=js;
                }
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
    }
    else{
        for(int js=1;js<=n;js++){
            memset(pp,0,sizeof pp);
            for(int i=js;i<=n;i++){
                if(pp[a[i]]!=0){
                    eg=pp[a[i]]-1;
                    pp[a[i]]=i;
                }
                vt[eg+1]=a[i];
                eg++;
            }
            for(int i=1;i<=eg;i++){
                if(za2[vt[i-1]]!=js){
                    ans[vt[i-1]]++;
                    za2[vt[i-1]]=js;
                }
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
    }
    return 0;}
