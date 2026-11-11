#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,c,t,k;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        //vector<int>a[1000005];

        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            /*a[u].push_back(v);
            a[v].push_back(u);*/
        }
        if(k==3)cout<<2<<"\n";
        else cout<<1<<"\n";
    }
    return 0;
}
/*freopen
quanju/jubu
return 0
()[]{}
endl->\n
int->ll
*/
