#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,ans;
long long m,a[N];

int f(int l,int r){
    int mid=(l+r)/2;
    while(l==r-1){
        if(a[mid]>(a[l]+a[r])/2){
            r=mid;
            mid=(l+r)/2;
        }
        else if(a[mid]<(a[l]+a[r])/2){
            l=mid;
            mid=(l+r)/2;
        }
    }
    return mid;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("crytal.in","r",stdin);
    freopen("crytal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=0x3f3f3f3f;

    int b=f(1,n);
    for(int i=b;i>=1;i--){
        if(a[i]<a[b]&&m>0&&m>=a[b]-a[i]){
            a[i]=a[b];
            m-=a[b]-a[i];
        }


    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            ans++;
        }
    }
    cout<<ans+1;
    return 0;
}
