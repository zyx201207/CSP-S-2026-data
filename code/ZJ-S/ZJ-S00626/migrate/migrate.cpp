#include<bits/stdc++.h>
using namespace std;
long long C,T,n,k,a[2000005],f[2000005],ans,cnt[2000005],stp[2000005],x,y,z;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n==1){
            cout<<"0\n";
            continue;
        }
        if(C==11||C==12){
            k/=a[2]-a[1];
            cout<<(k>1?max(n-2*k+1,0ll):0)<<"\n";
            continue;
        }
        if(C==13||C==14){
            for(int i=1;i<=n;i++){
                if(a[i]-a[1]<=k&&a[n]-a[i]<=k){
                    x=i;
                    break;
                }
            }
            for(int i=1,j=1;i<x;i++){
                while(j<n&&a[j+1]-a[i]<=k)j++;
                f[i]=j;
            }
            for(int i=n,j=n;i>x;i--){
                while(j>1&&a[i]-a[j-1]<=k)j--;
                f[i]=j;
            }
            y=z=x+1;
            for(int i=1;i<x;i++){
                while(y<=n&&f[i]-f[y]+1>2)y++;
                while(z<=n&&f[i]-f[z]+1>1)z++;
                ans+=z-y;
            }
            cout<<ans<<"\n";
            continue;
        }
        for(int i=1,j=1;i<=n;i++){
            while(j<n&&a[j+1]-a[i]<=k)j++;
            f[i]=j;
        }
        ans=0;
        for(int i=1;i<=n;i++){
            cnt[i]=1;
            stp[i]=0;
            for(int j=i-1;j>0;j--){
                if(f[j]==j)break;
                y=min((long long)i,f[j]);
                stp[j]=stp[y]+1;
                x=cnt[y];
                if(stp[y]==stp[y-1]){
                    x+=cnt[y-1];
                    if(stp[y]==stp[y-2])x+=cnt[y-2];
                }
                cnt[j]=min(3ll,x);
                if(cnt[j]==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
