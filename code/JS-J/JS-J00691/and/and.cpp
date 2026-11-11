#include <bits/stdc++.h>
using namespace std;
int a[200003],num[33];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
        int ans=0;
        for(int mask=0;mask<(1<<n);mask++){
            if(__builtin_popcount(mask)!=m) continue;
            int sum=-1;
            for(int i=1;i<=n;i++)
                if(mask&(1<<i-1)){
                    if(sum==-1) sum=a[i];
                    else sum=sum&a[i];
                }
            ans=max(ans,sum);
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(n<=2000){
        if(m==1){
            int ans=0;
            for(int i=1;i<=n;i++) ans=max(ans,a[i]);
            cout<<ans<<'\n';
        }
        else if(m==n){
            int ans=-1;
            for(int i=1;i<=n;i++){
                if(ans==-1) ans=a[i];
                ans=ans&a[i];
            }
            cout<<ans<<'\n';
        }
        else if(m==2){
            int ans=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<i;j++) ans=max(ans,a[i]&a[j]);
            cout<<ans<<'\n';
        }
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++)
                if(a[i]&(1<<j)) num[j]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++)
                if(a[i]&(1<<j)) num[j]--;
            int sum=0;
            for(int j=0;j<30;j++)
                if(num[j]==n-1) sum+=(1<<j);
            ans=max(ans,sum);
            for(int j=0;j<30;j++)
                if(a[i]&(1<<j)) num[j]++;
        }
        cout<<ans<<'\n';
        return 0;
    }
    bool f=1;
    for(int i=1;i<=n;i++){
        bool f1=0;
        for(int j=1;j<=30;j++)
        if(a[i]==(1<<j)-1){
            f1=1;
            break;
        }
        if(!f1){
            f=0;
            break;
        }
    }
    if(f){
        sort(a+1,a+n+1);
        cout<<a[n-m+1]<<'\n';
        return 0;
    }
    f=1;
    bool f2=0;
    for(int i=1;i<=30;i++)
        if(n==(1<<i)){
            f2=1;
            break;
        }
    for(int i=1;i<=n;i++)
        if(a[i]!=i-1){
            f=0;
            break;
        }
    if(f and f2){
        int s=0,p=n;
        for(int i=n;i>0;i/=2){
            if(m<=i and m>i/2){
                cout<<s<<'\n';
                return 0;
            }
            p/=2;
            s+=p;
        }
    }
    f=1;
    for(int i=1;i<=n;i++){
        if(a[i]>4){
            f=0;
            break;
        }
    }
    if(f){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]==4) cnt++;
        if(cnt>=m){
            cout<<4<<'\n';
            return 0;
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<2;j++)
                if(a[i]&(1<<j))
                    if(j==0) cnt1++;
                    else cnt2++;
        }
        if(min(cnt1,cnt2)>=m)cout<<3<<'\n';
        else if(cnt2>=m) cout<<2<<'\n';
        else if(cnt1>=m) cout<<1<<'\n';
        else cout<<0<<'\n';
        return 0;
    }
    cout<<0<<'\n';
    return 0;
}
