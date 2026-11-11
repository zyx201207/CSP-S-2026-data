#include<bits/stdc++.h>
using namespace std;
int tot,ver[2000005],head[1000005],nex[1000005],d[1000005];
void add(int x,int y){
    ver[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k,ans=0,xx=0;
        cin>>n>>k;
        tot=0;
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            add(a,b);
            add(b,a);
        }
        ans=ceil((n/2+1-k)/4);
        ans++;
        cout<<max(0,ans)<<'\n';
    }
    return 0;
}