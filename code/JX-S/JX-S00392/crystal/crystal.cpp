#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int a[N],b[N];
int n,m,ans;
inline int read(int &a){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return a=x*f;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    int la=1;
    int i=2;
    int res=1;
    int d=0;
    int cnt=1;
    while(i<=n){
        d+=cnt*b[i];
        while(d>m){
            d-=a[i]-a[la];
            la++;
            cnt--;
        }
        cnt++;
        ans=max(ans,cnt);
        i++;
    }
    cout<<ans;
    return 0;
}