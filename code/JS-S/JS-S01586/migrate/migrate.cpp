#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int a[2000005],la[2000005],ra[2000005];
int dis[501][501];
signed main(){
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n>500){
            memset(ra,0,sizeof ra);
            int ans=0;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            for(int i=1;i<=n;i++){
                int l=0,r=n+1,mid;
                while(l<r){
                    mid=l+r>>1;
                    if(a[mid]<=a[i]+d)l=mid+1;
                    else r=mid;
                }
                ra[l-1]++;
                l=1,r=n;
                while(l<r){
                    mid=l+r>>1;
                    if(a[mid]>=a[i]-d)r=mid;
                    else l=mid+1;
                }
                la[i]=l;
                ans+=ra[la[i]+1];
            }
            cout<<ans<<endl;
        }
        else{
            int ans=0;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            memset(dis ,0x3f,sizeof dis);
            for(int i=1;i<=n;i++){
                for(int k=1;k<=n;k++){
                    for(int j=1;j<=n;j++){
                        if(abs(a[i]-a[j])<=d)
                            dis[i][j]=dis[j][i]=2;
                        else dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]-1);
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    int sum=0;
                    for(int k=1;k<=n;k++){
                        if(dis[i][j]==dis[i][k]+dis[k][j]-1)
                            sum++;
                    }
                    if(sum==2)ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
}

