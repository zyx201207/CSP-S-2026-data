#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
bool check(int x,int y,long long d){
    if(a[y]-a[x]<=d){
        return 0;
    }
    int i;
    for(i=x+1;i<=y;i++){
        if(a[i]-a[x]>d){
            break;
        }
    }
    i--;
    int j;
    for(j=y-1;j>=x;j--){
        if(a[y]-a[j]>d){
            break;
        }
    }
    j++;
    if(i==j+1&&a[y]-a[i]<=d&&a[j]-a[x]<=d){
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int cc,T;
    cin>>cc>>T;
    while(T--){
        int n;
        long long d;
        cin>>n>>d;
        bool f=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>=2&&a[i]-a[i-1]!=a[2]-a[1]){
                f=0;
            }
        }
        int cnt=0;
        if(f==1){
            long long cha=a[2]-a[1];
            long long dd=d/cha;
            if(dd<=1){
                cout<<0<<"\n";
                continue;
            }
            long long ans,ans1=0;
            ans=n-dd-dd+1;
            ans=max(ans1,ans);
            cout<<ans<<"\n";
            continue;
        }
        if(n<=300){
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(check(i,j,d)){
                        cnt++;
                    }
                }
            }
            cout<<cnt<<"\n";
            continue ;
        }

    }
    return 0;
}
