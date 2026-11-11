#include<bits/stdc++.h>
#define pcr(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rcp(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+3;
const ll inf=1e9;
const int mod=998244353;
int n,m,a[N],num,ans[N];
int head,rear[N],tail,q[N];
void solve(){
    cin>>n>>m;
    pcr(i,1,n,1){
        cin>>a[i];
        rear[a[i]]=i;
    }
    head=n,tail=n;
    while(head>0){
        pcr(i,rear[a[head]],tail,1) q[i]++;
        if(a[head]==a[tail]) tail=head;
        rear[a[head]]=head;
        //pcr(i,1,m,1) tail=max(head,rear[a[i]]);
        head--;
    }
    //pcr(i,1,n,1) cout<<q[i]<<(i==n?"\n":" ");
    pcr(i,1,n,1){
        ans[a[i]]+=q[i];
    }
    pcr(i,1,m,1) cout<<ans[i]<<" ";
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    T=1;
    while(T--) solve();
    return 0;
}
