#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int C,T,n,d,x[N],l[N],r[N],t[N],is1[N],sum[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        int p=1,ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            while(p<=i&&x[i]-x[p]>d) p++;
            l[i]=p;
        }
        p=n;
        for(int i=n;i>=1;i--){
            while(p>=i&&x[p]-x[i]>d) p--;
            r[i]=p;
            //cout<<i<<' '<<r[i]<<' ';
        }
        for(int i=1;i<=n;i++){
            int p=i;
            for(int j=i;j<=n;j++){
                is1[j]=0;
                sum[j]=0;
                if(l[j]==j&&j>i) break;
                while(r[p]<j&&p!=r[p]) p=r[p];
                if(j<=r[i]) is1[j]=1;
                if(l[j]==p&&j>r[i]&&is1[p]) is1[j]=1;
                else if(l[j]==p&&j>r[i]&&!is1[p])ans+=sum[p],sum[j]=sum[p];
                if(l[j]==p-1&&is1[l[i]]&&is1[p]&&j>r[i]){
                    ans++;
                    sum[j]=1;
                    //cout<<i<<' '<<p<<' '<<j<<'\n';
                }
                //cout<<j<<' '<<l[j]<<' '<<r[p]<<'\n';
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
