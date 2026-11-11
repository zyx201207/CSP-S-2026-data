#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int N = 2e6+5;
const int mod = 1e9+7;
const int K = 5;
const int inf = 1<<30;
const bool debug = 0;
#define file "migrate"
//24 pts ?
ll n,d;
ll pos[N];
bool fgA = 1;
ll delta = 0;


ll re();
void judge();
void sol();
void read();

int main(){
    if(!debug){
        freopen(file".in","r",stdin);
        freopen(file".out","w",stdout);
    }
    ll c = re(),t = re();
    while(t--){
        judge();
    }
    return 0;
}

void read(){
    fgA  = 1;
    delta  =0;
    n  = re(),d = re();
    for(int i = 1;i <= n ;i++){
        pos[i] = re();
        if(i > 1){
            if(!delta){
                delta = pos[i] - pos[i-1];
            }
            else if(pos[i] - pos[i-1] != delta){
                fgA = 0;
            }
        }
    }
}

int minlen = 0,rescnt = 0;

void dfs(int i,int aim,int len){
    if(len > minlen)return;
    if(i == aim){
        if(minlen > len){
            minlen = len;
            rescnt = 1;
        }
        else if(minlen == len){
            rescnt ++ ;
        }
        return;
    }
    for(int j = i+1;j <= aim;j++){
        if(pos[j]-pos[i] <= d){
            dfs(j,aim,len+1);
        }
        else{
            break;
        }
    }
}

int check(int u,int v){
    minlen = v-u+2;
    rescnt = 0;
    dfs(u,v,0);
    return (minlen != v-u+2 && rescnt == 2);
}

void force(){
    ll ans = 0;
    // printf("%d\n",check(1,4));
    // return;
    for(int u = 1;u <= n;u++){
        for(int v = u+1;v <= n;v++){
            ans += check(u,v);
        }
    }
    printf("%lld\n",ans);
}

void judge(){
   read();
   if(n <= 10){
       force();
   }
   else if(fgA){
       sol();
   }
   else{
       puts("0");
   }
}

void sol(){
    if(d < 2*delta){
        puts("0");
        return;
    }
    if(delta == 1){
        ll ans = (n-3) - (2 * (d-delta * 2));
        printf("%lld\n",max(0ll,ans));
        return ;
    }
    ll ans = (n-3) - (2 * (d-delta*2+1)/delta);
    printf("%lld\n",max(0ll,ans));
}

ll re(){
    ll x = 0,t = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')t = -t;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9'){
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return x * t;
} 