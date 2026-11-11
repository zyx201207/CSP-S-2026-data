#include <iostream>
using namespace std;
const int N=2*1e5;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long ans=111111111;
    long long max=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans&=a[i];
        if(a[i]>max) max=a[i];
    }
    if(m==n) cout<<ans;
    else{
        cout<<max;
    }
    return 0;
}

