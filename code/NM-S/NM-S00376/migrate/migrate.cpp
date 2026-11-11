#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,once;
bool j2=false;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        cout<<n-((a[n]-a[1])/d)<<endl;
    }
    return 0;
}
