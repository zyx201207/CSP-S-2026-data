#include <bits/stdc++.h>
using namespace std;
int n,c,t,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int a,b;
        for(int i=1;i<=n;i++)cin>>a>>b;
        if(n==k)cout<<0;
        else{
            n=(n-1)/2-k;
            if(k==1){
                if(n/2*2!=n)cout<<n/2+2;
                else cout<<n/2+1;
                cout<<endl;
                continue;
            }
            if(n/4*4!=n)cout<<n/4+2;
            else cout<<n/4+1;
        }
        cout<<endl;
    }
    return 0;
}
