#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
const int MAXN=2e6+10;
int c,T,n,d,ans=0;
int x[MAXN],dp1[MAXN],dp2[MAXN],pre[MAXN],p1[MAXN];
inline void init(){
    ans=0;
    for(int i=1;i<=n;i++)dp1[i]=dp2[i]=pre[i]=0;
    return;
}
inline int bnrs(int l,int r,int tx){//tx=x[j]-d
   // if(r==1)return 0;
    while(l<r){
        if(x[mid]>=tx)r=mid;
        else l=mid+1;
    }
    return mid;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        init();
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        dp1[1]=0;
        for(int i=2;i<=n;i++){
            pre[i]=bnrs(1,i,x[i]-d);

            int pos=pre[i];
            dp1[i]=dp1[pos]+i-pos;
            p1[i]=dp1[i]+p1[i-1];
            dp2[i]=dp2[pos];
            int pp=pre[pos];
            if(i-pos>=2){
                    int lst1=pre[pos+1],lst2=pre[pos+2];
                    dp2[i]+=p1[lst2]-p1[lst1];

            }
            ans+=dp2[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 1
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
