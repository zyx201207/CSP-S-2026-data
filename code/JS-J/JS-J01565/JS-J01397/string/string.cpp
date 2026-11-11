#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
int a[200005];
char c[200005];
long long q[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    q[0]=0;
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    long long t=(q[n]+1)/2;
    int ll=1,rr=n;
    while(ll<rr-1){
        int m=(ll+rr)/2;
        if(q[m]<t)
            ll=m;
        else
            rr=m;
    }
    t=q[n]/2;
    long long l=1,r=q[n];
    int i2=n,i=1;
    while(i<=ll+1){
        if(c[i2]==c[i]){
            if(a[i]>=a[i2]){
                t-=a[i2];
                r-=a[i2];
                l+=a[i2];
                a[i]-=a[i2];
                i2--;
            }
            else{
                t-=a[i];
                l+=a[i];
                r-=a[i];
                a[i2]-=a[i];
                i++;
            }
        }
        else{
            if(a[i]>=a[i2]){
                r-=a[i2];
                l+=a[i2];
                a[i]-=a[i2];
                i2--;
            }
            else{
                l+=a[i];
                r-=a[i];
                a[i2]-=a[i];
                i++;
            }            
        }

    }
    t-=(r-l)/2;
    printf("%lld\n",t);
    return 0;
}