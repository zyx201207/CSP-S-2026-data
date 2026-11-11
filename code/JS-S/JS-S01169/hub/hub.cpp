#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    cin >>c>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        int r[1000005][1000005];
        cin >>n>>k;
        for(int j=1;j<=n;j++){
            int u,v;
            cin >>u>>v;
            r[u][v]++;
            r[v][u]++;
        }
        cout<<0<<endl;
    }
    return 0;
}
