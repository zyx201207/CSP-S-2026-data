#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],b[500010],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int l=1,r=1;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];

        if(i>2){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                flag=false;
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=0;i<=n;i++){
        b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    while(r<=n && !flag){
        if(r<l) r=l;
        if((b[r]-((l-1)*(a[r]-a[l])+b[l]))<=m){
            ans=max(ans,r-l+1);
            r++;
        }
        else{
            l++;
        }
    }
    if(flag){
        m=m/(a[2]-a[1]);
        while(m>=0){
            ans++;
            m-=ans;
        }
    }
    cout<<ans;
    return 0;
}
