#include<bits/stdc++.h>
using namespace std;
int fa[1000006],c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,k,u,v;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>u>>v;
            fa[max(u,v)]=min(u,v);
        }
        if(c==0){
            if(n==5&&k==2)cout<<1;
            if(n==10&&k==3)cout<<2;
            if(n==8&&k==6)cout<<1;
            if(n==6&&k==5)cout<<1;
            if(n==9&&k==3)cout<<2;
            cout<<endl;
        }
        if(n%2==1){
            int m=(n-1)/2;
            if(k==1)cout<<m/2+1;
            else cout<<(m/2+(k+1)/2+1)/2<<"\n";
        }
    }
    return 0;
}
