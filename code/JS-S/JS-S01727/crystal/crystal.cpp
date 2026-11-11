#include <bits/stdc++.h>
using namespace std;
int a[500005];
long long b[500005];
long long c[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int ans=1;
    long long m;
    cin>>n>>m;
    int x=0;
    bool f1=true,f2=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            f2=false;
        }
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]+a[i]-a[i-1];
        if(i>=3&&b[i]-b[i-1]!=b[2]){
            f1=false;
        }
    }
    if(f1||f2){
        int sum=0,ans=1;
        while(sum<=m){
            ans++;
            sum+=b[ans]-b[1];
        }
        cout<<ans-1;
        return 0;
    }
    for(int i=n;i>=1;i--){
        int sum=0,cnt=i;
        if(b[i]-b[i-1]>=m){
            continue;
        }
        if(i<=ans){
            break;
        }
        while(sum<=m&&cnt>=1){
            cnt--;
            sum+=b[i]-b[cnt];
        }
        ans=max(ans,i-cnt);
    }
    cout<<ans;
    return 0;
}
