#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long ans[N];
long long n,m,a[N],mp[N],pre[N],pre2[N],sz[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
        for(int i=n;i>=1;i--){
            if(mp[a[i]]==0){
                pre[i]=-1;
            }else{
                pre[i]=mp[a[i]];
            }
            mp[a[i]]=i;
        }
        for(int j=1;j<=n;j++){
            int i=j;
            while(i<=n){
                if(pre[i]==-1){
                    ans[a[i++]]++;
                }else{
                    i=pre[i];
                }
            }
        }
    }else if(n<=500000){
        bool g=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i+1]){
                g=0;
            }
        }
        if(g){
            for(int i=2;i<=n;i++){
                if(a[i]!=a[i-1]){
                    ans[a[i-1]]=i-1;
                }
            }
        }else{
            for(int i=n;i>=1;i--){
                if(mp[a[i]]==0){
                    pre[i]=-1;
                }else{
                    pre[i]=mp[a[i]];
                }
                if(a[i]==a[i+1]){
                    pre2[i]=pre2[i+1];
                }else{
                    pre2[i]=i;
                    sz[i]=1;
                }
                mp[a[i]]=i;
            }
            for(int j=1;j<=n;j++){
                int i=j;
                while(i<=n){
                    if(pre[pre2[i]]==-1){
                        ans[a[i]]++;
                        i=pre2[i]+1;
                    }else{
                        i=pre[pre2[i]];
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
