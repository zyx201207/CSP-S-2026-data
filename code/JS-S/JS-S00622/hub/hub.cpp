#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+3;
int c,t,n,k;
int v[N],u[N],num[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        int ma = 0;
        cin>>n>>k;
        for(int i = 1;i < n;i++){
            cin>>u[i]>>v[i];
            num[u[i]]++;
            ma = max(ma,num[v[i]]);
        }
        cout<<ma<<endl;
    }

    return 0;
}
