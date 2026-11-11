#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5; 
int c,T,f[N],n,d,lst[N];
__int128 a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for (int i=1,x;i<=n;i++){
            cin>>x;a[i]=x;
        }
        int ans=0;lst[1]=1;
        for (int i=2;i<=n;i++){
            int l=1,r=i;lst[i]=i;
            while(l<=r){
                int mid=(l+r)/2;
                if (a[i]-a[mid]<=(__int128)d){
                    lst[i]=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            // cout<<lst[i]<<" ";
            f[i]+=f[lst[i]];
            int lst1=lst[i]+1;
            if (lst1==i)    continue;
            f[i]+=lst[i]-lst[lst1]+1;
            int lst2=lst[i]+2;
            f[i]-=lst[i]-lst[lst2]+1;
            ans+=f[i];
        }
        // cout<<"\n";
        // for (int i=2;i<=n;i++)  cout<<f[i]<<" ";
        // cout<<"\n";
        cout<<ans<<"\n";
        for (int i=0;i<=n;i++)  f[i]=a[i]=lst[i]=0;
    }
    return 0;
}