#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],nxt[2000010],ne,minn,num;
void dfs(int u,int v,int x){
    if(u==v){
        num++;
        return;
    }
    if(x>=minn)return;
    if(num>2)return;
    for(int i=nxt[u];i>u;i--){
        dfs(i,v,x+1);
        if(num>2)return;
    }
}
bool check(int u,int v){
    int x=u;
    minn=num=0;
    while(x!=v){
        if(nxt[x]==x)return false;
        if(nxt[x]>v){
            x=v;
        }
        else{
            x=nxt[x];
        }
        minn++;
    }
    dfs(u,v,0);
    if(num==2){
        return true;
    }
    return false;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        nxt[0]=2;
        for(int i=1;i<=n;i++){
            nxt[i]=nxt[i-1];
            ne=0;
            for(int j=nxt[i];j<=n;j++){
                if(x[j]-x[i]>d){
                    ne=j-1;
                    break;
                }
            }
            if(ne==0){
                nxt[i]=n;
            }
            else{
                nxt[i]=ne;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(check(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
