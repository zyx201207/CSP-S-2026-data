#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll  n,A,B,Aans,Bans,k=1,h,f,m,a[N],sum[N],d[N],zu;
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2&&a[i]==a[i-1])    f++;
        if(a[i]==i)               A++;
        if(i>=2){
            d[i]=a[i]-a[i-1];
        }
    }
    for(int i=3;i<=n;i++){
        if(d[i]==d[i-1])    h++;
    }
    if(d[2]!=1&&h==n-2){
        B=d[2];
        while(m>=B){
            m=m-B;
            B*=2;
            Bans++;
        }
        cout<<Bans+1<<"\n";
        return 0;
    }
    if(A==n){
        while(m>=k){
            m-=k;
            k++;
            Aans++;
        }
        cout<<Aans+1<<"\n";
        return 0;
    }

    if(n==1){
        cout<<1<<"\n";
        return 0;
    }

    if(f==(n-1)){
        cout<<n<<"\n";
        return 0;
    }
    sort(a+1,a+1+n);
    ll ans;
    ll l=1;
    ll r=n;
    ll mid=(1+n)/2;
    ll mn=1e17+5;
    while(l!=r){
        for(int i=mid;i<=n;i++){
            for(int j=i-mid+1;j<i;j++){
                sum[i]+=a[i]-a[j];
            }
            mn=min(sum[i],mn);
        }
        if(mn<m){
            l=mid+1;
            if(l==r){
                for(int i=1;i<=l;i++){
                    zu+=a[l]-a[i];
                    if(zu<m){
                        cout<<l-1;
                        return 0;
                    }
                }
            }
            mid=(l+r)/2;
            ans=mid;
        }
        if(mn==m){
            ans=mid;
            break;
        }
        if(mn>m){
            r=mid-1;
            mid=(l+r)/2;
            ans=mid;
        }
        zu=0;
        mn=1e17+5;
        for(int i=1;i<=n;i++)    sum[i]=0;
    }
    cout<<ans<<"\n";
    return 0;
}
