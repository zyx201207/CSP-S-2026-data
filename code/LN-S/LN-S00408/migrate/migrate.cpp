//天空你是否知晓一切
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar();
    }
    return x*f;
}
int c,T;
const int N = 1e5+6;
int gaojia(int a, int b){
    char x[20]={},y[20]={},he[20]={};
    int cntx=0, cnty=0;
    while(a>0){
        x[cntx++] = a%10;
        a/=10;
    }
    while(b>0){
        y[cnty++]=b%10;
        b/=10;
    }
    //for(int i = 0; i < cntx; i++)cout << x[i];
    for(int i = 0; i < max(cntx, cnty); i++){
        if(x[i]+y[i]+he[i]<10)he[i]=x[i]+y[i]+he[i];
        else{
            he[i] = (x[i]+y[i]+he[i])%10;
            he[i+1]++;
        }
    }
    int ans = 0,cnt=1;
    for(int i = 0; i < max(cntx, cnty)+1; i++){
        ans += he[i]*cnt;
        cnt *= 10;
    }
    return ans;
}
int gaojian(int a, int b){
    int f = 1;
    if(b>a)swap(a,b),f=-1;
    char x[20]={},y[20]={},he[20]={};
    int cntx=0, cnty=0;
    while(a>0){
        x[cntx++] = a%10;
        a/=10;
    }
    while(b>0){
        y[cnty++]=b%10;
        b/=10;
    }
    //for(int i = 0; i < cntx; i++)cout << x[i];
    for(int i = 0; i < max(cntx, cnty); i++){
        if(x[i]-y[i]+he[i]>=0)he[i]=x[i]-y[i]+he[i];
        else{
            he[i] = 10+x[i]-y[i]+he[i];
            he[i+1]--;
        }
    }
    int ans = 0,cnt=1;
    for(int i = 0; i < max(cntx, cnty); i++){
        ans += he[i]*cnt;
        cnt *= 10;
    }
    return ans*f;
}
int gao(int a, int b){
    if(a == 0)return b;
    if(b == 0)return a;
    if(a > 0 && b > 0)return gaojia(a,b);
    if(a < 0 && b > 0)return gaojian(b,-a);
    if(a > 0 && b < 0)return gaojian(a,-b);
    if(a < 0 && b < 0)return (-1)*gaojia(-a,-b);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    c=read(),T=read();
    if(c == 12 || c == 11){
        while(T--){
            int n = read(), d = read();
            int ks = read(), kb = read();
            for(int i = 3; i <= n; i++)int x = read();
            int cha = gaojian(kb,ks);
            int mo = d*1.0/cha;
            cout << n-mo-1<<"\n";
        }
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    while(T--){
        int n = read(), d = read(),ans=0;
        int x[N]={},dp[N]={};
        for(int i = 1 ; i <= n; i++)x[i]=read();
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                memset(dp,0x3f, sizeof(dp));
                dp[i]=0;
                for(int k = i+1; k < j; k++){
                    for(int p = k-1; p >= i; p--){
                        if(x[k]<=gao(x[p],d))dp[k] = min(dp[k],dp[p]+1);
                    }
                }
                int cnt = 0;
                for(int p = j-1; p >= i; p--){
                    if(x[j]<=gao(x[p],d)){
                        if(dp[j]> dp[p]+1)dp[j]=dp[p]+1,cnt=1;
                        else if(dp[j] == dp[p]+1)cnt++;
                    }
                }
                if(cnt == 2)ans++;
            }

        }
        printf("%lld\n",ans);
    }
    //cout << gao(c,T);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
