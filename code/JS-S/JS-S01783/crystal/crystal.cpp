#include<bits/stdc++.h>
using namespace std;

#define int long long
namespace io{
    int read(){
        int k=0,f=1;
        char c=getchar_unlocked();
        while(c<'0'||c>'9'){
            if(c=='-'){
                f=-1;
            }
            c=getchar_unlocked();
        }
        while(c>='0'&&c<='9'){
            k=k*10+c-'0';
            c=getchar_unlocked();
        }
        return k*f;
    }
    void write(int x){
        if(x<0){
            putchar('-');
            x=-x;
        }
        if(x<10){
            putchar(x+'0');
        }else{
            write(x/10);
            putchar(x%10+'0');
        }
    }
    template<class T>void read(T&x){x=read();}
    template<class First,class... Args>void read(First&first,Args&... arg){read(first);read(arg...);}
    template<class T>void write(T x){write(x);}
    template<class First,class... Args>void write(First first,Args... arg){write(first);write(arg...);}
}
using namespace io;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // freopen("crystal.err","w",stderr);
    int n,m;
    read(n,m);
    vector<int>a(n+1),cf(n+1),cnt1(n+1),cnt3(n+1);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a.begin()+1,a.end());
    cnt1[1]=cnt3[1]=0;
    for(int i=2;i<=n;i++){
        cf[i]=a[i]-a[i-1];
        cnt1[i]=cnt1[i-1]+cf[i];
        if(a[i]!=a[i-1])cnt3[i]=cnt3[i-1]+(i-1)*cf[i];
        // if(a[i]!=a[i-1])cnt3[i]=cnt3[i-1]+cnt1[i];
        else cnt3[i]=cnt3[i-1];
        // cnt2[i]=cnt2[i-1]+cf[i]*(i-1);
    }
    // cerr<<cnt3[n]<<endl;
    // for(int i=1;i<=n;i++){
    //     cerr<<a[i]<<" ";
    // }
    // cerr<<endl;
    // for(int i=1;i<=n;i++){
    //     cerr<<cf[i]<<" ";
    // }
    // cerr<<endl;
    // for(int i=1;i<=n;i++){
    //     cerr<<cnt1[i]<<" ";
    // }
    // cerr<<endl;
    // for(int i=1;i<=n;i++){
    //     cerr<<cnt3[i]<<" ";
    // }
    // cerr<<endl;
    vector<int>dp(n+1,0);
    dp[1]=1;
    int ans=0;
    for(int i=2;i<=n;i++){
        int l=i-1-dp[i-1]+1;
        for(int j=l;j<=i;j++){
            // cerr<<i<<" "<<j<<":"<<cnt3[i]-(j-1)*(cnt1[i]-cnt1[j-1])-cnt3[j-1]<<" ";
            if(cnt3[i]-(j-1)*(cnt1[i]-cnt1[j-1])-cnt3[j-1]<=m){
                dp[i]=i-j+1;
                ans=max(ans,dp[i]);
                // cerr<<dp[i]<<endl;
                break;
            }
            // cerr<<dp[i]<<endl;
        }
    }
    cout<<ans<<endl;
    // for(int i=1;i<=n;i++){
    //     cerr<<dp[i]<<" ";
    // }
    return 0;
}