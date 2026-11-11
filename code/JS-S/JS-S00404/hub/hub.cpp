#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long x,y;
    cin>>x>>y;
    for(int i=1;i<=y;i++){
        cout<<rnd()%4<<'\n';
    }
    return 0;
}
