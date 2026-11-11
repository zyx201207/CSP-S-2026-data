#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b,l[200005],r[200005],f[200005],s;
char c[200005];
string d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],b=max(b,a[i]);
    if(n*b<=100000000){
        for(int i=1;i<=n;i++) for(int j=1;j<=a[i];j++) d=d+c[i];
        for(int i=0;i<=d.size()/2;i++) if(d[i]!=d[d.size()-i-1]) s++;
        cout<<s;
        return 0;
    }
    for(int i=1;i<=n;i++) l[i]=r[i-1]+1,r[i]=r[i-1]+a[i];
    if(n<2001){
        for(int i=1;i<=n;i++){
            long long L=r[n]-r[i]+1,R=r[n]-l[i]+1;
            for(int j=i;j<=n;j++){
                if(c[j]==c[i]) continue;
                if(l[j]<=L&&r[j]>=L&&r[j]<=R) s+=(r[j]-L+1);
                else if(l[j]>=L&&r[j]<=R) s+=(r[j]-l[j]+1);
                else if(l[j]>=L&&l[j]<=R&&r[j]>=R) s+=(R-l[j]+1);
            }
            f[i]=1;
        }
        cout<<s;
        return 0;
    }
    return 0;
}
