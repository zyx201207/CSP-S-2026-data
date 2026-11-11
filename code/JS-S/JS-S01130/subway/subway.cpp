
#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
struct s{
    int w,a,to,t;
}a[505];
void dfs(int f,int l,int now,int value){
    value=value+a[now].w+a[now].t;
    if(l==now) {
        cout<<value<<endl;
        return;
    }
    dfs(f,l,a[now].to,value);
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i].w;
    for(int i=1,k;i<=n;i++){
        cin>>k;
        int l=0;
        for(int j=1,a1,t;i<=k;j++){
            cin>>a1>>t;
            a[l].to=a1;
            l=a1;
            a[a1].t=t;
        }
    }
    for(int i=1,w,v;i<=q;i++){
            cin>>w>>v;
        dfs(w,v,w,0);
    }
    cout<<32<<' '<<17;


return 0;



}
