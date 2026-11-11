#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define LL long long
LL a[N];
int b[N],c[N];
int nb[N],nc[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int sub,t;
    cin>>sub>>t;
    while(t--){
        int n;
        LL d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(nb,0,(n+1)<<2);
        memset(nc,0,(n+1)<<2);
        LL ans=0;
        int i=1,j=1;
        while(i<=n){
            while(j<=n && a[j]-a[i]<=d)j++;
            b[i++]=j-1;
        }for(int i=n;i>1;i--){
            if(b[i]!=i && b[i]!=b[i-1])nb[i]=nb[b[i]]+1;
        }
        i=n;j=n;
        while(i>0){
            while(j>0 && a[i]-a[j]<=d)j--;
            c[i--]=j+1;
        }for(int i=1;i<n;i++){
            if(c[i]!=i && c[i]!=c[i+1])nc[i]=nc[c[i]]+1;
        }

        for(int i=2;i<n-1;i++){
            if(a[i+1]-a[i]>d)continue;
            int l1=c[i+1],l2=b[i-1]+1,r1=c[i+2]-1,r2=b[i];
            if(l1>r1 || l2>r2 || l1==i || r2==i+1)continue;
            int l=r1-l1+1,r=r2-l2+1;
            if(b[i+1]==r2)r+=nb[r2];
            if(c[i]==l1)l+=nc[l1];
            ans+=(LL)l*r;
        }cout<<ans<<'\n';
    }
    return 0;
}
