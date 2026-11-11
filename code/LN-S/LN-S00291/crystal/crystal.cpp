#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],ans=1;
int main(){
    #define int long long
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    f[1]=0;
    for(int i=2,j=1;i<=n;i++){
        f[i]=f[i-1]+(a[i]-a[i-1])*(i-j);
        if(f[i]>m){
            while(j<=i){
                f[i]-=(a[i]-a[j]);
                j++;
                if(f[i]<=m)
                    break;
            }
        }
        ans=max(ans,i-j+1);
//        cout<<i-j+1<<' ';
    }
    cout<<ans;
    return 0;
}
