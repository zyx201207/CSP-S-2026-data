#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500005]{};
int cost[500005]{},indcost[500005];
int cnt=0;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool flag=true;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int maxx=-1e5;
    sort(a+1,a+n+1);
    for(int i=3;i<=n;++i){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
            flag=false;
            break;
        }
    }
    if(!flag){
        for(int i=1;i<n;++i){
            cost[i]=a[i+1]-a[i];
            indcost[i]=indcost[i-1]+cost[i];
        }

        for(int i=2;i<=n;++i){
            int co=0;
            for(int j=i-1;j>0;--j){
                co+=indcost[i-1]-indcost[j-1];
                if(co<=m){
                    maxx=max(maxx,i-j+1);
                }
                else break;
            }
        }
    }
    else {
        int tm=0;
        int diff=a[2]-a[1];
        for(int i=1;i<=n;++i){
            if(tm>m){
                cout<<i-1<<endl;
                return 0;
            }
            else tm+=diff*i;
        }
        cout<<n;
        return 0;
    }
    cout<<maxx;
    return 0;
}
