#include<bits/stdc++.h>
using namespace std;
long long a[500005],x=1,m2,ans=1,bj=0,bh=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        if(m-(a[x+1]-a[x])*x>=0){
            m=m-(a[x+1]-a[x])*x;
            bh++;
            x++;
        }
        if(x>n-1){
            break;
        }
    }
    cout<<bh;
    cout<<endl;
    return 0;
}
