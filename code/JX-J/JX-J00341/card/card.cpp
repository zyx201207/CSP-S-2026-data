#include<bits/stdc++.h>
using namespace std;
int n,m,en;
int a[500005],q[500005],ans[300005];
bool f;
bool v[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        en=1;
        memset(q,0,sizeof(q));
        memset(v,0,sizeof(v));
        for(int j=i;j<=n;j++){
            f=0;
            for(int k=1;k<=en-1;k++){
                if(f==0&&q[k]==a[j]){
                    f=1;
                    en=k+1;
                }
                if(f==1){
                    q[k]=0;
                }
            }
            q[en]=a[j];
            en+=1;
        }
        for(int j=1;j<=en;j++){
            if(v[q[j]]==0){
                ans[q[j]]++;
                v[q[j]]=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
