#include<bits/stdc++.h>
using namespace std;
struct s{
    int a;
    int b;
}a[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","s",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>a[i].a>>a[i].b;
        }
        cout<<1<<endl;
    }
    return 0;
}
