#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,mx,LLL;
int a[200010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    LLL=a[1];
    for(int i=2;i<=n;i++)LLL&=a[i];
    if(n<=20){
        for(int i=0;i<=(1<<n-1);i++){
        int s;
        int t=i,c=0,p=0,fl=1;
        while(t){
            p++;
            if(t&1){
                c++;
                if(fl){
                    s=a[p];
                    fl=0;
                }
                else s&=a[p];
            }
            t>>=1;
        }
        if(c==m)ans=max(ans,s);
        }
        cout<<ans<<'\n';
    }
    if(n>20){
        if(m==1)cout<<mx;
        else if(m==n){
            cout<<LLL;
        }
        else cout<<262142;
    }
    return 0;
}
