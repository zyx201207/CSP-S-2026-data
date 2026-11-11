#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll res=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=10*res+ch-'0';
        ch=getchar();
    }
    return res*f;
}
void outt(ll x){
    if(x<0){
        x=-x;
    }
    char ch=x%10+'0';
    if(x>=10)outt(x/10);
    putchar(ch);
}
const int N=2e6+5;
ll c,t,n,d,x[N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    t=read();
    while(t--){
            ans=0;
        n=read();
        d=read();
        for(int i=1;i<=n;i++){
            x[i]=read();
        }
        for(int i=1;i<=n;i++){
            int j,k;
            for(j=i;j<=n;j++){
                if(j==n)break;
                if(x[j+1]-x[i]>d)break;
            }
            for(k=j;k<=n;k++){
                if(k==n)break;
            if(x[k+1]-x[j]>d)break;
            }
            ans+=(k-i);
        }
        outt(ans);
        putchar('\n');
    }
    return 0;
}

