#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1000100;

void exam();
ll sab(int,int);
void mak_inti();

ll n,m;

ll a[N];
ll sh[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    exam();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
void exam(){
    
    scanf("%lld%lld",&n,&m);
    bool fa=1;
    ll d;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i==2){
            d=a[2]-a[1];
        }
        if(a[i]-a[i-1]!=d&&fa&&i>2){
            fa=0;
        }
    }
    if(fa){
        ll k=2*m/d;
        ll ans=(1+sqrt(1+4*k))/2;
    }
    sort(a+1,a+n+1);
    mak_inti();
    int maxx=INT_MIN;
    for(int i=n;i>=1;i--){
        int cr=0;
        for(int j=i;j>=1;j--){
            int ss=sab(j,i);
            if(ss>m)break;
            cr=i-j+1;
        }
        maxx=max(cr,maxx);
    }
    printf("%d",maxx);
}
void mak_inti(){
    ll sum=0;
    for(int i=n;i>=1;i--){
        sum+=a[n]-a[i];
        sh[i]=sum;
    }
}
ll sab(int u,int b){
    return sh[u]-sh[b]-(a[n]-a[b])*(b-u);
}