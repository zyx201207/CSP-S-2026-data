#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ma=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    int tool=1073741824,t2=30;
    while(tool>ma){
        tool/=2,t2--;
    }
    int ans=0;
    while(tool!=0){
        int nm=0;
        for(int i=1;i<=n;i++)if(a[i]>=tool)nm++;
        if(nm>=m){
            ans+=tool;
            for(int i=1;i<n;i++){
                if(a[i]>=tool)a[i]-=tool;
                else a[i]=0;
            }
            tool/=2,t2--;
        }
        else{
            for(int i=1;i<=n;i++)if(a[i]>=tool)a[i]-=tool;
            tool/=2,t2--;
        }
    }
    cout<<ans;
    return 0;
}
