#include<bits/stdc++.h>
using namespace std;
int c,m,t,d,w[10000001],q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    cout<<w[c]+w[t];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
