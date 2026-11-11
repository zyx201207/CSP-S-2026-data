#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
#define ll long long
ll n,m,a[N],c[N];
int ans=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=n-1;i>0;i--){
        int sum=1,m1=m;
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]<=m1) m1-=(a[i]-a[j]),sum++;
            else break;
            //cout<<a[i]<<' '<<a[j]<<'\n';
        }
        ans=max(ans,sum);
        //cout<<ans<<' '<<sum<<'\n';
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
