#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N],cnt,lbj,sum,ans,res;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++) cnt+=b[i];
    if(cnt==0){
        cout<<n;
        return 0;
    }
    else if(cnt==(n-1)*b[2]){
        for(int i=1;i<=n;i++){
            lbj+=i;
            if(lbj*b[2]>m){
                cout<<i;
                return 0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            sum+=a[i]-a[j];
            if(sum>m){
                res=ans;
                ans=max(res,i-j);
                sum=0;
                break;
            }
            else if(sum<=m&&j==1){
                res=ans;
                ans=max(res,i-j+1);
                sum=0;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
