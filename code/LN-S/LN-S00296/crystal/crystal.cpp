#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
int main (){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    long long q=a[n]-a[n-1];
    long long need=q,k=2,ans=1;
    while(m>=need){
        m-=need;
        need+=q;
        k++;
        ans++;
    }
    cout<<ans;

    return 0;
}
