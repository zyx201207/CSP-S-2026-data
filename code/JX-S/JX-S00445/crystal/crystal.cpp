#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],d[500005];
long long ans=0;
long long l=1,cnt=0;
long long read(){
    long long p,res=0;
    bool neg=false;
    while(p!=EOF&&(p<'0'||p>'9')){
        p=getchar();
        if(p=='-')neg=true;
    
    }
    while(p!=EOF&&('0'<=p&&p<='9')){
        res=res*10+p-'0';
        p=getchar();
    
    }
    if(neg)res=-res;
    return res;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
//    cin>>n>>m;
    for(int i=1;i<=n;i++){
        //cin>>
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }
    /*
    a[l..k-1]->a[k]
    cost=(k-l)*a[k]-pre[k-1]+pre[l-1];
    cost=(k+1-l)*a[k+1]-pre[k-1]-a[k]+pre[l-1];
    delta[k+1][l]=(k+1-l)a[k+1]-(k-l)*a[k]-a[k]
         =(k+1-l)(a[k+1]-a[k])
    delta[k][l]=(k-l)*d[k];
    
    */
    for(int i=1;i<=n;i++){
        cnt+=(i-l)*d[i];
        while(cnt>m){
            cnt-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}
