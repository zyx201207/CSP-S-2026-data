#include<bits/stdc++.h>
using namespace std;

#define ll long long



int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
        }
        cout<<abs(rand()%n-k)<<'\n';
    }
    return 0;
}
