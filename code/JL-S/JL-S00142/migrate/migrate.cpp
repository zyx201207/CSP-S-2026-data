#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    while(t-->0){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int T=a[2]-a[1];
        if(T>d){
            cout<<"0\n";
        }
        else if(T<=d&&d<2*T){
            cout<<n-1<<"\n";
        }
        else{
        int ans=0;
                for(int i=1;i<=n;i++){
                    if(d>=i*T)ans+=n-1;
                    else break;
                }
                cout<<ans<<"\n";
        }
        
    }
    return 0;
}

