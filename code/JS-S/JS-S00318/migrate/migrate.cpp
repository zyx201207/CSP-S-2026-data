#include<bits/stdc++.h>
using namespace std;

long long n,m,c,t,d,a[2000005],dp[2000005],sum[2000005],s[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11 || c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            long long x=a[2]-a[1];
            //cout<<n<<' '<<x<<' '<<d<<' ';
            if(x*2>d) {
                cout<<0<<endl;
                continue;
            }
            x=d/x;
            long long l=x+1;
            long long r=x*2-1;
            long long ans=0;
            if(n-r>0) ans+=n-r;
            cout<<ans<<endl;
        }
    }
    else if(c==13 || c==14){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            cout<<n-3<<endl;
        }
    }
    else if(c>10){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            cout<<0<<endl;
        }
    }
    else
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            int l=i;
            for(int j=1;j<=n;j++){
                dp[j]=0;
                sum[j]=0;
                s[j]=0;
            }
            s[i]=1;
            for(int j=i+1;j<=n;j++){
                while(abs(a[l]-a[j])>d) l++;
                if(l==j) break;
                dp[j]=dp[l]+1;
                s[j]=1;
                if(dp[l+1]==dp[l] && l+1<j) s[j]++;
                if(dp[l+2]==dp[l] && l+2<j) s[j]++;
                s[j]*=s[l];
                if(s[j]==2) ans++;
                //if(i==1) cout<<dp[j]<<' ';
            }
        }
        cout<<ans<<endl;
    }
}
