#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int a[N],b[N];
int n,m;

bool check(int i,int j){
    return (i-j+1)*a[i]-(b[i]-b[j-1])<=m;
}

int f(int x){
    int l=1,r=x,mid;
    while(l<r){
        mid=(l+r)/2;
        if(check(x,mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return x-r+1;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f(i));
    }
    cout<<ans<<endl;
    return 0;
}
