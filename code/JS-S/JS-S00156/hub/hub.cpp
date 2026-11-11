#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,k,ma;
long long a[5010][5010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n>>k;
        for(int i=1;i<n;i++){
            long long x,y;
            cin>>x>>y;
        }
        long long t=n/2+1;
        if(t>k)
        cout<<(t-k)/4+1<<endl;
        else if(n==k)
            cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
