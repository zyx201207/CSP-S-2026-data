#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int n,m;
int a[500005];
bool check(int x){
    for(int i=1;i+x-1<=n;i++){
        int j=i+x-1;
        int cnt=0;
        int maxn=-1e16;
        for(int k=i;k<=j;k++){
            maxn=max(maxn,a[k]);
        }
        for(int k=i;k<=j;k++){
            cnt+=maxn-a[k];
        }
        if(cnt<=m) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int i=1,j=n,ans=0;
    while(i<=j){
        int mid=(j-i)/2+i;
        if(check(mid)){
            ans=mid;
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
