#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,t,n,k,u,v;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u>>v;
        }
        cout<<min(k-1,2)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
