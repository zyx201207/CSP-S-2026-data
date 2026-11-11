#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n,k;
vector<int> a[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if(n==k){
            cout<<0;
        }
    }

    return 0;
}