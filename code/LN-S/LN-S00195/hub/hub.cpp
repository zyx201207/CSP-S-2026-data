#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdin);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k;
        int u[n],v[n];
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
        int minn=INT_MAX;
        for(int i=1;i<n;i++){
            if(u[i]<minn)minn=u[i];
            if(v[i]<minn)minn=v[i];

        }
        cout<<minn<<'\n';
    }
    return 0;
}
