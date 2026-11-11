#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans,sum[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
    }
    int q=n+1,r=0;
    long long l=sum[n]%2==0?sum[n]/2:(sum[n]-1)/2;
    int m=lower_bound(sum+1,sum+n+1,l)-sum,R=sum[m]-l;
    //if(R) m--;
    //cout<<m<<" "<<R<<'\n';
    for(int i=1;i<=m;i++){
        //cout<<q<<" "<<r<<" ";
        int p=lower_bound(sum+1,sum+n+1,sum[n]-sum[i])-sum;
        if(p==q){
            if(c[i]!=c[p]) ans+=a[i];
            continue;
        }
        if(r&&c[q]!=c[i]) ans+=r;
        for(int j=p+1;j<q;j++) if(c[j]!=c[i]) ans+=a[j];
        int rr=sum[p]-sum[n]+sum[i];
        if(rr&&c[p]!=c[i]) ans+=rr;
        q=p;
        r=a[p]-rr;
        //cout<<q<<" "<<rr<<" "<<ans<<'\n';
    }
    //m++;
    //if(R&&c[m]!=)
    cout<<ans;
    return 0;
}