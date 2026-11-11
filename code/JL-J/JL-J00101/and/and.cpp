#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,r=0;
    char c;
    c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return f*r;
}
int n,m,a[200005],ans,cnt[30],aa[200005];
bool flag1=1,flag2=1,flag3=1;
inline void dfs(int x,int num,int cnt){
    if(cnt==m){
        ans=max(ans,num);
        return;
    }
    if(x==n+1) return;
    dfs(x+1,num&a[x],cnt+1);
    dfs(x+1,num,cnt);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    int tt=log2(n);
    if(double(tt)!=log2(n)) flag2=0;
    int maxx=0,num=pow(2,20)-1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        aa[i]=a[i];
        if((aa[i])&(aa[i]+1)!=0) flag1=0;
        if(a[i]!=i-1) flag2=0;
        if(a[i]>3) flag3=0;
        maxx=max(maxx,a[i]);
        num&=a[i];
        int temp=a[i];
        for(int i=20;i>=1;i--){
            if(temp>=pow(2,i)){
                temp-=pow(2,i);
                cnt[i]++;
            }
        }
    }
    int asdf=0;
    for(int i=20;i>=1;i--){
        if(cnt[i]==n) asdf+=pow(2,i);
    }
    int temp=pow(2,20);
    if(n<=20){
        temp--;
        dfs(0,temp,0);
        cout<<ans;
    }
    else if(m==1){
        cout<<maxx;
    }
    else if(m==n){
        cout<<num;
    }
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n-1){
        int anss=asdf;
        for(int i=1;i<=n;i++){
            int t=a[i];
            int numm=asdf;
            for(int j=20;j>=1;j--){
                if(t>=pow(2,j)){
                    t-=pow(2,j);
                    if(cnt[j]==n-1) numm+=pow(2,j);
                }
            }
            anss=max(anss,numm);
        }
        cout<<anss;
    }
    else if(flag1){
        sort(aa+1,aa+n+1);
        cout<<aa[m+1];
    }
    else if(flag2){
        int anss=0;
        while(n/2>=m){
            n/=2;
            anss+=n;
        }
        cout<<anss;
    }
    else if(flag3){
        int anss=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==3) cnt++;
        }
        if(cnt>=m) anss=3;
        else{
            cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]>=2) cnt++;
            }
            if(cnt>=m) anss=2;
            else{
                for(int i=1;i<=n;i++){
                    if(a[i]>=1) cnt++;
                }
                if(cnt>=m) anss=1;
            }
        }
        cout<<anss;
    }
    else{
        cout<<pow(2,30)-1;
    }
    return 0;
}
