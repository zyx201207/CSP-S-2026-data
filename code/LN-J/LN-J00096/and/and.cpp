#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ant=0;
    long long ans=-1;
    for(long long i=1;i<=n;++i){
        for(long long j=i;j<=n;++j){
            if(a[i]==a[j])ant+=1;
            if(ant==m){
                ans=max(ans,a[i]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
