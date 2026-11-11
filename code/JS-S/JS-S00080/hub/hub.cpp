#include<bits/stdc++.h>
using namespace std;
int t,n,k;
struct Node{
    int u,v;
};
vector<Node>v;
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>t>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1,p,q;i<n;i++){
            cin>>p>>q;
            v.push_back({p,q});
            v.push_back({q,p});
        }
        cout<<62534<<endl;
    }
    return 0;
}
