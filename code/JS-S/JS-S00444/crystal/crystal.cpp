#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,sum,cnt[500010],b[500010];
int a[500010];
int k,all,kk;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]!=i) k=1;
    }
    for (int i=2;i<=n-1;i++){
        if (a[i+1]-a[i]!=a[i]-a[i-1]) kk=1;
    }
    if (n<=5000){
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++){
            sum=0;
            memset(b,0,sizeof b);
            for (int j=i;j<=n;j++){
                b[j]=a[i]-a[j];
                sum+=b[j];
                if (sum>m){
                    cnt[i]=j-i;
                    break;
                }
            }
            if (sum<=m){
                cnt[i]=n-i+1;
            }
        }
        sort(cnt+1,cnt+n+1,cmp);
        cout<<cnt[1];
        return 0;
    }else if(k==0){
        for (int i=1;i<=n;i++){
            all+=i;
            if (all>m){
                cout<<i;
                return 0;
            }
        }
    }else if(kk==0){
        int d=a[2]-a[1];
        for (int i=1;i<=n;i++){
            all+=i;
            if (d*all>m){
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}
