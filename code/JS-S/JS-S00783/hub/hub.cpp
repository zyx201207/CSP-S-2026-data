#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
        }
        int ans=((n+1)/2-k+1)/4;
        if(((n+1)/2-k+1)%4!=0)ans++;
        cout<<ans<<endl;
    }

    return 0;
}
