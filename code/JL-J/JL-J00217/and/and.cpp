#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
int n,m;
int a[N],s[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int maxn=-1e9,sum=0,cnt=0;
    for(int i=m;i<=n;i++){
        int ii=m-5+i;
        sum=0;cnt=m-2;
        sum=a[i]&a[i-1];
        while(cnt>=1){
            int z=sum;
            sum=z&a[ii];
            --ii;cnt--;
        }
        maxn=max(maxn,sum);
    }
    cout<<maxn;
    return 0;
}

