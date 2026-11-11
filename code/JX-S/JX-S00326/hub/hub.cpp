#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[500005],u[500005],v[500005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
        cout<<k-1<<endl;
    }
    return 0;
}
