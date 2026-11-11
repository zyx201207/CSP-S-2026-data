#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long d[500005];
long long a[500005];
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+int(ch-'0');
        ch=getchar();
    }
    x*=f;
    return x;
}
long long m;
bool check(int mid,int x){
    int j=1;
    long long sum=0;
    for(int i=mid+1;i<=x;i++,j++){
        sum+=j*d[i];
        if(sum>m) return false;
    }
    return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
//    cin>>n>>m;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    bool f=false;
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        if(i>2&&d[i]!=d[i-1]) f=true;
    }
    if(!f){
        int y=d[n];
        //x*(x-1)*y<=2m
        int lf=1,rf=n;
        int ansf=0;
        while(lf<=rf){
            int midf=(lf+rf)/2;
            if(midf*(midf-1)*y<=2*m){
                ansf=midf;
                lf=midf+1;
            }else rf=midf-1;
        }
        cout<<ansf<<'\n';
        return 0;
    }
    int ans=1;
    for(int i=2;i<=n;i++){
        int l=1,r=i-1;
        while(l<=r&&(i-l+1)>ans){
            int mid=(l+r)/2;
            if((i-mid+1)<=ans){
                r=mid-1;
            }
            else if(check(mid,i)){
                r=mid-1;
                ans=max(i-mid+1,ans);
            }else l=mid+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
