#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],b[N];int ans;

bool check(int mid){
    int sum=0;
    for(int i=1;i<mid;i++){
        sum+=a[mid]-a[i];
    }
    if(sum<=m) return true;
    return false;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            int sum=0,j;
            for(j=i-1;j>=1;j--){
                sum+=a[i]-a[j];
                if(sum>m) {
                    break;
                }
            }
            ans=max(ans,i-j);
        }
        cout<<ans;
    }
    else{
        for(int i=1;i<=n;i++){
            b[i]=a[i]-a[1];
        }
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        cout<<ans;
    }

    return 0;
}
/*/
5 8
-3 -1 2 2 7
/*/
