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
#define file "crystal"
//100 pts!
ll n,m;
ll arr[N];
ll pre[N];

ll re();
void judge();
void sol();
void read();


int main(){
    if(!debug){
        freopen(file".in","r",stdin);
        freopen(file".out","w",stdout);
    }
    judge();
    return 0;
}

void read(){
     n = re(),m = re();
     for(int i = 1;i <= n;i++)arr[i] = re();
     sort(arr+1,arr+1+n);
}

void judge(){
    read();
    sol();
}

//
bool check(int i,int d){
    //[i,d]
    int len = d-i+1;
    ll sum = pre[d] - pre[i-1];
    ll aimsum = arr[d] * len;
    ll need = aimsum - sum;
    return need <= m;
}

void sol(){
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i-1]  + arr[i];
    }
    int ans = 0;
    for(int i = n;i >= 1;i--){
        ll aim = arr[i];
        if(aim - arr[i-1] > m){
            //if pre one has over m then i skip
            continue;
        }
        if(check(1,i)){
            ans = max(i,ans);
            // printf("%d:%lld : res = %d\n",i,arr[i],i);
            continue;
        }
        int res = 0;
        int l = 1,r = i;
        while(l < r){
            int mid = (l+r)>>1;
            if(check(mid,i)){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        int ok = i-res+1;
        // printf("%d:%lld : res = %d\n",i,arr[i],ok);
        ans = max(ok,ans);
    }
    printf("%d\n",ans);
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