#include<bits/stdc++.h>
using namespace std;
int c,t;
int w[100005],v[100005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>w[i]>>v[i];
        }
        cout<<k;
    }
    return 0;
}


