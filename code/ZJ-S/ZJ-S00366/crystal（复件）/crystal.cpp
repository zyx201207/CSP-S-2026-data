#include<iostream>
#include<algorithm>
using namespace std;
namespace YuJH{
    int n;
    long long m;
    long long a[500010],s[500010];
    int l,r,mid,res;
    int ans;
    int main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+a[i];
        for(int i=1;i<=n;i++){
            l=1;
            r=i;
            res=i;
            while(l<=r){
                mid=(l+r)>>1;
                if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
                    r=mid-1;
                    res=mid;
                }
                else
                    l=mid+1;
            }
            ans=max(i-res+1,ans);
        }
        cout<<ans;
        return 0;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    YuJH::main();
    return 0;
}