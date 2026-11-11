#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub5.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t, n, k;
    cin>>c>>t;
    while(t--){
        cin>>n;
        cout<<((n/2+1)%2==1?((n/2+2)/2):((n/2+1)/2));
    }
    return 0;
}
