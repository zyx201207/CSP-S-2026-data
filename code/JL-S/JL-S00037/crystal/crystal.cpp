#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],s[N],d1,d2;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'&&c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=read(),m=read();
    bool ok=true;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(ok){
        d2=a[i]-a[i-1];
        if(d1!=d2)ok=false;
        d1=d2;
        }
    }

    sort(a+1,a+1+n);
    if(ok){
        int res=1;
        while(m>0){
            m-=d1*res;
            res++;
        }
        if(m<0)res--;
        cout<<res;
        return 0;
    }
    s[1]=0;
    int ans=0;
    for(int i=2;i<=n;i++){
        s[i]=a[i]-a[i-1];
        for(int j=i-1;j>=1;j--){
            s[j]=s[i]+s[j]+(i-j)*s[i];
            if(s[j]>m){ans=max(ans,i-j);break;}
        }

    }

    cout<<ans+1;
    return 0;
}
