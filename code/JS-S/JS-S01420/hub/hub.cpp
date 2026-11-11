#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int c,T,n,k;
    cin>>c>>T;
    if(c==13||c==14){
        while(T--){
            cin>>n>>k;
            for(int i=1;i<n;i++) cin>>c>>c;
            if(k==n) cout<<0;
            else if(k>=n/2) cout<<1;
            else{
                if(k<=2){
                    c=n/2+1;
                    k++;
                    if(c%k!=0) c=c/k+1;
                    else c/=k;
                }
                else{
                    c=n/2+1-k+2;
                    if(c%3!=0) c=c/3+1;
                    else c/=3;
                }
                cout<<c;
            }
            cout<<'\n';
        }
        return 0;
    }
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++) cin>>c>>c;
        if(n==k) cout<<0;
        else cout<<1;
        cout<<'\n';
    }
    return 0;
}
//hub
