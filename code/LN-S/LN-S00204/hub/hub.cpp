#include<bits/stdc++.h>
using namespace std;
using in=long long;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","out",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int x,y;
        for(int i=1;i<n;i++){
            cin>>x>>y;
        }
        cout<<k-1<<'\n';
    }
    return 0;
}
