#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 4e18;
long long n,m,ans,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    bool isAB=true;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(i>=2){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                isAB=false;
            }
        }
    }

    if(isAB&&n>5000){
        double d=double(a[1]-a[0]);
        cout<<floor((pow(d*d+8*d*m,0.5)-d)/2/d)+1<<"\n";
        return 0;
    }


    sort(a,a+n);

    for(int i=0;i<n;++i){
        long long tot=0,cnt=0;
        for(int j=i;j>=0;--j){
            tot+=a[i]-a[j];
            if(tot<=m){
                ++cnt;
            }else{
                break;
            }
        }
        ans=max(ans,cnt);
    }

    cout<<ans<<"\n";
    return 0;
}