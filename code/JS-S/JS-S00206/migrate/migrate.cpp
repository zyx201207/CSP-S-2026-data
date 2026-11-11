#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int c,t,n,d,a[2000010],b[2000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-1;i++){
            b[i]=a[i+1]-a[i];
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                int dist=0;
                int ans1=0,ans2=0;
                for(int now=i;now<=j;now++){
                    if(dist+b[now]>=d){
                        dist=b[now];

                    }
                }
            }
        }
    }

    return 0;
}
