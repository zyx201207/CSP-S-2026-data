#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int gc=x[n]-x[n-1];
        if(c==11||c==12){
            if(d<2*gc){
                cout<<0<<endl;
                continue;
            }
            cout<<n-3<<endl;
        }
    }
    return 0;
}
