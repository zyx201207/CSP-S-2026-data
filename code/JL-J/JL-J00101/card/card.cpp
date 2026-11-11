#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,r=0;
    char c;
    c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return f*r;
}
int n,m,ans[10005],a[10005],vis[10005];
bool flag=1;
stack<int> stk;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) flag=0;
    }
    if(flag){
        int tot=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=tot){
                cout<<i-1<<' ';
                tot++;
            }
        }
        cout<<n;
        return 0;
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        if(a[n]==1){
            for(int i=n-1;i>=1;i--){
                if(a[i]==2){
                    a[0]=1;
                    for(int j=i-1;i>=0;i--){
                        if(a[j]==1){
                            cout<<n<<' '<<i-j;
                            return 0;
                        }
                    }
                }
            }
        }
        else{
            for(int i=n-1;i>=1;i--){
                if(a[i]==1){
                    a[0]=2;
                    for(int j=i-1;i>=0;i--){
                        if(a[j]==2){
                            cout<<i-j<<' '<<n;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(!stk.empty() && stk.top()!=a[j]){
                    vis[stk.top()]=0;
                    stk.pop();
                }
            }
            else{
                stk.push(a[j]);
                vis[a[j]]=1;
            }
        }
        while(!stk.empty()){
            ans[stk.top()]++;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
