#include<bits/stdc++.h>
#define i32 signed
#define i64 long long
#define int i64
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
int n,m;
int ans;
int a[N],b[N];
i32 main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
        int l=1,r=i,x=i;
        while(l<=r){
            int mid=l+r>>1;
            if((i-mid+1)*a[i]-b[i]+b[mid-1]<=m)r=mid-1,x=mid;
            else l=mid+1;
        }
        ans=max(ans,i-x+1);
    }cout<<ans;
    return 0;
}
//14:50