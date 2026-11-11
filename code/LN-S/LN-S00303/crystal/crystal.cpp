#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[10010000];
int b[10010000];
int ans;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }

    for(int i=1;i<=n;i++){
        int l=1;
        int r=i;
        int mid;
        while(l<r){
            mid=(l+r)/2;
            if(a[i]*(i-mid)-(b[i-1]-b[mid-1])<=m){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
        //cout << i-l+1 << endl;
    }
    cout << ans;
    return 0;
}
