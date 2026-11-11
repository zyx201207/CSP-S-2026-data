#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int c,T,n,d,x[N];
int L[N],R[N],dpL[N],dpR[N];
int sumL[N],sumR[N],ans,cntL[N],cntR[N];
void Solve(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i],dpL[i]=dpR[i]=cntL[i]=cntR[i]=0;
    int lst=1;
    for(int i=1;i<=n;i++){
        R[i]=lst;
        while(R[i]+1<=n&&x[R[i]+1]-x[i]<=d) R[i]++;
        lst=R[i];
        cntR[R[i]]++;
    }
    lst=n;
    for(int i=n;i>=1;i--){
        L[i]=lst;
        while(L[i]-1>=1&&x[i]-x[L[i]-1]<=d) L[i]--;
        lst=L[i];
        cntL[L[i]]++;
    }
    for(int i=1;i<=n;i++){
        //dpL[i]=cntR[i]+1;
        if(R[L[i]]!=i) dpL[i]=cntR[i]+1;
        else dpL[i]=cntR[i];
        if(L[i]!=i&&R[L[i]]==i) dpL[i]+=dpL[L[i]];
    }
    for(int i=n;i>=1;i--){
        if(L[R[i]]!=i) dpR[i]=cntL[i]+1;
        else dpR[i]=cntL[i];
        if(R[i]!=i&&L[R[i]]==i) dpR[i]+=dpR[R[i]];
    }
    //int awa=6;
    //int calc=0;
    //while(R[awa]!=awa&&L[R[awa]]==awa) calc++,awa=R[awa],cerr<<awa<<"\n";
    //cerr<<calc+1<<"\n";
    for(int i=1;i<=n;i++) sumL[i]=sumL[i-1]+dpL[i],sumR[i]=sumR[i-1]+dpR[i];
    for(int i=1;i<=n;i++){
        if(i==R[i]) continue;
        if(R[R[i]]==R[i]) continue;
        if(i+1==R[i]) continue;//L[R[i]-1]!=i
        int myl,myr;
        int l=R[i]+1,r=n;
        bool flag=1;
        while(l<r){
            int mid=l+r>>1;
            if(L[mid]<R[i]-1) l=mid+1;
            else r=mid;
        }
        myl=l;
        if(L[myl]!=R[i]-1) flag=0;
        l=R[i]+1,r=n;
        while(l<r){
            int mid=l+r+1>>1;
            if(L[mid]>R[i]-1) r=mid-1;
            else l=mid;
        }
        myr=r;
        if(L[myr]!=R[i]-1) flag=0;
        //if(flag) ans+=dpL[i]*(myr-myl+1);
        // cerr<<i<<":"<<myl<<","<<myr<<"\n";
        // flag=1;
        // if(L[R[R[i]]]!=R[i]-1) flag=0;
        // if(flag) ans+=dpR[R[R[i]]]-1;
        //cout<<i<<"\n";
        //S E
        if(flag) ans+=myr-myl+1;//cout<<"S E:"<<myr-myl+1<<"\n";
        //S !E
        if(L[R[R[i]]]==R[i]-1) ans+=dpR[R[R[i]]]-1;//cout<<"S !E:"<<dpR[R[R[i]]]-1<<"->"<<R[R[i]]<<"\n";
        //!S E
        if(flag&&L[R[i]-1]==i) ans+=(dpL[i]-1)*(myr-myl+1);//cout<<"!S E:"<<(dpL[i]-1)*(myr-myl+1)<<"\n";
        //!S !E
        if(L[R[i]-1]==i&&L[R[R[i]]]==R[i]-1) ans+=(dpL[i]-1)*(dpR[R[R[i]]]-1);//cout<<"!S !E:"<<(dpL[i]-1)*(dpR[R[R[i]]]-1)<<"\n";
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    cin>>c>>T;while(T--) Solve();
    return 0;
}