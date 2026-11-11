#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500010];
long long ans=1;
bool isAll=0;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=1e9+1;

    sort(a+1,a+n+1);

    int i=1;
    while(m>=0 && isAll==0){
        int c=a[i+1]-a[i];
        c*=i;
        m-=c;
        if(m>=0){
            ans++;
        }
        if(i>=n){
            isAll=1;
        }
        i++;
    }
    cout<<ans<<endl;

    return 0;
}
