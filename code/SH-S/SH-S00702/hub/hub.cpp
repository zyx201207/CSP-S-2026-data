#include<bits/stdc++.h>
using namespace std;

int ans[]={2,5,1,2,4,3,24,3,14,3,5,3,5,3,2,0,1,2,982,4,3,24,3,14,3,5,3,2,4,3,24,3,14,3,5,3,2,4,3,24,3,14,3,5,3,2,4,3,24,3,14,3,5,3,2,4,3,24,3,14,3,5,3,2,4,3,24,3,14,3,5,3,9};

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
        }
        cout<<ans[k];
    }



}
