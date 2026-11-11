#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        n++;
        int x;
        for(int i=1;i<n-1;i++)cin>>x>>x;
        cout<<(n/2-k+1)/4+1<<'\n';
    }
    return 0;
}
