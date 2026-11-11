#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n;
    cin>>n>>n>>n>>n>>n;
    for(int i=1;i<=n;i++){
        int x;
        x=((i*2003&99)|77^83*i&7|i)%107;
        if(x==0){
            x=(x+(6^9&329)*i-9&3+(894&i&35)*45)%103;
        }
        cout<<x<<"\n";
    }
    return 0;
}
