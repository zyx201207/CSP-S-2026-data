#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,l=1,ans=1,cnt=1;
    long long m,ma=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        ma+=(a[i]-a[i-1])*(i-l);
        cnt++;
        while(ma>m){
            cnt--;
            ma-=a[i]-a[l];
            l++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}