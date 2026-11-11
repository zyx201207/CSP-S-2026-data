#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int x[200005];
int f[300005];
vector<int>a[200005];
void dfs(int k,int sum,int n){
    if(k==n){
        f[sum]++;
    }
    for(int i=0;i<a[k].size();i++){
        dfs(a[k][i],sum+1,n);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            f[i]=0;
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    a[i].push_back(j);

                }
            }
        }
        for(int i=1;i<n-2;i++){
            for(int j=i+3;j<=n;j++){
                dfs(i,0,j);
                for(int l=1;l<=j-i;l++){
                    if(f[l]==2){
                        ans++;
                    }
                    f[l]=0;
                }
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            a[i].clear();
        }

    }
    return 0;
}

