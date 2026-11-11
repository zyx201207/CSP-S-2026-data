#include<bits/stdc++.h>
using namespace std;
typedef long long l;
l dr(){
    l x=0,f=1;
    char c=getchar();
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
l n,m,ans,a[200005];
void dfs(l la,l t,l s){
    if(t==m){
        ans=max(ans,s);
        return;
    }
    for(l i=la+1;i<=n;i++){
        dfs(i,t+1,(s&a[i]));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=dr();
    m=dr();
    for(l i=1;i<=n;i++){
        a[i]=dr();
    }
    for(l i=1;i<=n;i++){
        dfs(i,1,a[i]);
    }
    cout<<ans;
    return 0;
}
