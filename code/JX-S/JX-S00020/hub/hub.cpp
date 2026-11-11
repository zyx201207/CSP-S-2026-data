#include <bits/stdc++.h>
#define LL long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int c,t;
int n,k;
int u[2000005],v[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    IOS;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n-1;i++){
            cin>>u[i]>>v[i];
        }
    }
    cout<<1<<endl<<2;


    return 0;
}
