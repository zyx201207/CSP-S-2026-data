#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[700001];
bool flag=true;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=false;
        }
    }
    if(flag){
        int d=a[2]-a[1],x=1;
        while((x+1)*x*d/2<=m)x++;
        cout<<x<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    cerr<<"Start\n";
    while(l<r-1){
        int mid=(l+r)/2;
        cerr<<"The medium now: "<<mid<<", Range: "<<l<<','<<r<<endl;
        //break;
        for(int j=1;j<=n-mid+1;j++){
            int sum=0;
            for(int i=j;i<=j+mid-1;i++){
                sum+=a[j+mid-1]-a[i];
                if(sum>m)break;
            }
            if(sum<=m)goto succ;
        }
        r=mid;
        continue;
        succ:;
        l=mid;
    }
    cout<<l<<endl;
    return 0;
}
