#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int n,m,a[N],b[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=1;
        int mm=m;
        for(int j=i;j<n;j++){
            if(mm-(b[j+1]-b[j])*(j-i+1)>=0){
                mm-=(b[j+1]-b[j])*(j-i+1);
                b[j]=b[j+1];
                b[j-1]=a[j-1];
                res++;
            }
            else{
                b[j-1]=a[j-1];
                break;
            }
        }
        ans=max(ans,res);
    }
    cout<<ans<<"\n";
    return 0;
}
