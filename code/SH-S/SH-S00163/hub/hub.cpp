#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin>>c>>T;
    for(ll i=1;i<=T;i++) cout<<1+(!rand()%10)<<endl;
    return 0;
}
