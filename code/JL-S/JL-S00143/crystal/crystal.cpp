#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500799;
int n,ans;
ll m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        ll x=a[i]-a[i-1];
        while(l<r){
            mid=(l+r)>>1;
            if(a[i]-a[mid-1]+m<x*(i-mid+1))
                l=mid+1;
            else
                r=mid;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d\n",ans);
    return 0;
}
//g++ -Wall -std=c++14 -fsanitize=address crystal.cpp -o crystal;./crystal