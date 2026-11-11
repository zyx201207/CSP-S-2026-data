#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
int n,m;
set<int>s;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=-1;
    for(int i=1;i<=n*n;i++){
        int cnt=0;
        s.clear();
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                if(s.find(k)==s.end()){
                    s.insert(k);
                    if(cnt|a[k]==0){
                        cnt=a[k];
                    }
                    else{
                        cnt|=a[k];
                    }

                }

            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
