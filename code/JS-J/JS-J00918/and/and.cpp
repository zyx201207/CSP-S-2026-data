#include<bits/stdc++.h>;
using namespace std;
typedef long long ll;
const int N=2e5+3;
int a[N];
int kk[30]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823};

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int m,n;
    cin>>n>>m;

    bool spcA=1,spcB=1,spcC=1,c1=0,c2=0,c3=0;
    int maxn=0,andn;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(i==1) andn=a[i];
        else andn&=a[i];
        if((*(lower_bound(kk,kk+30,a[i])))!=a[i]) spcA=0;
        if(a[i]!=i-1) spcB=0;
        if(a[i]>4) spcC=0;
        if(a[i]==1) c1++;
        if(a[i]==2) c2++;
        if(a[i]==3) c3++;
    }

    if(m==1){cout<<maxn<<endl;return 0;} // 5 point get
    if(m==n){cout<<andn<<endl;return 0;} // 5 point get
    if(spcA){ // 5 point get
        sort(a+1,a+n+1);
        cout<<a[n-m+1]<<endl;
        return 0;
    }
    if(spcB){ // 10 point get
        cout<<n-m<<endl;
        return 0;
    }
    if(m==2){ // 15 point get
        sort(a+1,a+n+1);
        cout<<(a[n] & a[n-1])<<endl;
        return 0;
    }
    if(spcC){
        if(c3>=m) cout<<3<<endl;
        if(c3+c2>=m) cout<<2<<endl;
        if(c3+c1>=m) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }

    sort(a+1,a+n+1);
    int ans=a[n];
    for(int i=n-1;i>=n-m+1;i++) ans=(ans & a[i]);
    cout<<ans<<endl;

    return 0;
}
