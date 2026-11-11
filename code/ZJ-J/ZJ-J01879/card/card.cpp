#include<bits/stdc++.h>
#define db(x) cout<<#x<<" "<<x<<endl;
#define int long long
using namespace std;
int n,m,ans[500010],a[500010],b[500010],c[500010],lt[500010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int s=1;s<=n;s++){
        int now=0;
        for(int i=1;i<=m;i++) ls[i]=c[i]=0;
        for(int i=s;i<=n;i++){
                lt[now]=ls[a[i]];
            if(ls[a[i]]){
                while(now>ls[a[i]]){
                    ls[a[now]]=lt[now];
                    a[now]=0;
                    now--;
                }
            }
            else{
                b[++now]=a[i];
                ls[a[i]]=now;
            }
        }
        for(int i=1;i<=now;i++){
            c[b[i]]=1;
        }
        for(int i=1;i<=m;i++){
            ans[i]+=c[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
