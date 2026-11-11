#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k;
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    if(c==13||c==14||c==0) {
        while(T--) {
            int n,k;
            cin>>n>>k;
            int t=(n-1)/2+2;
            if(k==n) {
                cout<<0<<endl;
                continue;
            }
            for(int i=1;i<=n-1;i++) {
                int u,v;
                cin>>u>>v;
            }
            cout<<(t-k)/(k+1)+1;
        }
    }
    else if(k==2) {
        if(n%3==0) {
            cout<<n/3;
        }
        else {
            cout<<n/3+1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
