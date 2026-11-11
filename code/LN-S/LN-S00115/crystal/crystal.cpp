#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
long long n,ans,m,k,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(1){
        long long s=abs(a[k+1]-a[k]);
        m-=s;
        if(m<0){
            break;
        }
        ans++;
        k++;
    }
    cout<<ans<<endl;
    return 0;
}
