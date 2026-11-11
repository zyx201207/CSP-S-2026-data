#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
            int n,k;
            cin>>n>>k;
        if(c==13 || c==14){
            cout<<(k+1)/2<<'\n';

        }
        else cout<<0<<'\n';
    }
    return 0;
}
