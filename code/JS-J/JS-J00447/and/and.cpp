#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
    return x*f;
}int n,m,mmax;
int a[200010];
int e[30];
int ans;
map<int,int> mp;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    for(int i=1; i<=n; i++){
        a[i]=read();
        mmax=max(mmax,a[i]);
    }if(m==1){
        cout<<mmax<<endl;
        return 0;
    }if(m==2){
        int ans=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i!=j) ans=max(ans,a[i]&a[j]);
            }
        }cout<<ans<<endl;
        return 0;
    }if(m==n){
        for(int i=1; i<=n; i++){
            mmax&=a[i];
        }cout<<mmax<<endl;
        return 0;
    }
}