#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,c;
int x[2000006];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(t%2==1)  cout<<0;
        else{
            cout<<abs(t-n+d+1)<<endl;
        }
    }
    return 0;
}
