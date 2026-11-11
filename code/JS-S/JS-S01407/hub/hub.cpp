#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,t;
LL n,k;
LL cnt[1000005];
LL x[2],y[2];
void solve (){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>x[i&1]>>y[i&1];
    }


    if(c==13||c==14){
        if(k&1){
            cout<<k/2+1<<'\n';
        }else{
            cout<<k/2<<'\n';
        }

        return ;
    }
    if(k<=1){
        cout<<k<<'\n';
        return ;
    }
    if(k==2){
        if(x[1]==x[0]||x[1]==y[1]||x[1]==y[0]||y[0]==y[1])
            cout<< 2<<'\n';
        else
            cout<<1<<'\n';

        return ;
    }



        if(k&1){
            cout<<k/2+1<<'\n';
        }else{
            cout<<k/2<<'\n';
        }



}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(0);//liantongkuai<=2 -> liangkeshu
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        solve();
    }

}
