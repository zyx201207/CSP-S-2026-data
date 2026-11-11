// Crystal
// crystal.cpp
#include<bits/stdc++.h>
using namespace std;
#define LOGGER 0
#if LOGGER == 1
#define LOG(k) k
#else
#define LOG(k)
#endif
typedef long long sll;
typedef unsigned long long ull;
constexpr int N = 1e6;
int n;
sll a[N];
sll pre[N];
sll m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // LOG(cerr<<"Starting test."<<endl;)
    cin>>n>>m;
    for(int i=0;i<=n;i++)pre[i]=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;
    for(int j=1,i=1;i<=n;++i){
        while(j<=i&&((i-j)*a[i]-(pre[i-1]-pre[j-1]))>m)j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
