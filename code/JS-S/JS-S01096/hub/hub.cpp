#include<bits/stdc++.h>
#define N 2000001
#define inf 1e18
using namespace std;
int n,k;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int c,t;
    cin>>c>>t;
    int a,b;
    while(t--){
        cin>>n>>k;
       // for(int i=0;i<N;i++)edges[i].clear();
        for(int i=1;i<n;i++){
            cin>>a>>b;
           // edges[a].push_back(b);
           // edges[b].push_back(a);
        }
        if(n==k){
            cout<<0<<'\n';
            continue;
        }
        int m=(n-1)/2;
        if(k>=m){
            cout<<1<<'\n';
            continue;
        }
        if(k%2==0){
            if(m%2==0){
                cout<<((m/2)-(k/2)+1)<<'\n';
            }
            else{
                cout<<((m/2)-(k/2)+2)<<'\n';
            }
        }
        else{
            if(m%2==0){
                 cout<<((m/2)-(k/2))<<'\n';
            }
            else{
                 cout<<((m/2)-(k/2)+1)<<'\n';
            }
        }

    }
    return 0;
}
