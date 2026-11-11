#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],s[N];
int n,m;
int read(){
    int s=0,k=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')k=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*k;
}
void print(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x<=9){
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=1;
    int ans=1;
    while(l<=r&&r<=n){
        r++;
        if((a[r]*(r-l+1)-(s[r]-s[l-1]))<=m)ans=max(ans,r-l+1);
        else{
            while((a[r]*(r-l+1)-(s[r]-s[l-1]))>m)l++;
            ans=max(ans,r-l+1);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
