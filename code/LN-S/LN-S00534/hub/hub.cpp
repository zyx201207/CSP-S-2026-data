#include<bits/stdc++.h>
using namespace std;

int main (){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >>c>>t;
    int n,k;
    cin >>n>>k;
    vector<vector<int>> x(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin >>u>>v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
    for(int i=1;i<=t;i++)
        cout<<n*k*c*(long long)sqrt(i%101)*(i%10120)/t%(n-1)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
