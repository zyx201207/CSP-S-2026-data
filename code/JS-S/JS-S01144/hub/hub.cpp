#include <bits/stdc++.h>
using namespace std;
vector<int> u;
vector<int> v;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k;
    cin>>c>>t>>n>>k;
    for(int i=1;i<=n-1;i++){
        int u1,v1;
        cin>>u1>>v1;
        u[i]=u1;
        v[i]=v1;

    }
    int cnt_min=0;
    for(int i=1;i<=t;i++){
        cnt_min++;
        cout<<cnt_min;
    }




















    int l1;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l1++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l1++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l1++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            l1++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l1++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l1++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l1++;
        }
    }
    return 0;
}
