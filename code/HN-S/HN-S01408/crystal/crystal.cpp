#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;;
    vector<int>a(n+1);
    vector<int>cst(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }    
    sort(a.begin()+1,a.end());
    cst[n]=0;
    int xx=a[n];
    for(int i=n-1;i>=1;i--){
        cst[i]=xx-a[i]+cst[i+1];
    }
    int l=1,r=1;
    int ans=-1;
    for(;l<=n;l++){
        if(l>r){
            r=l;
        }
        for(;r<=n;r++){
            if((cst[l]-cst[r])-(a[n]-a[r])*(r-l+1)>m){
                break;
            }
        }
        ans=max(ans,(r-l));
    }
    cout<<ans<<endl;
    
    return 0;
}

