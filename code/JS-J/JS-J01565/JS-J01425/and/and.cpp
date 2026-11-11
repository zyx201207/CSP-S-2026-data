#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=2e5+10;
ll a[N];
bool d[N];
int n,m;

bool ck(ll mid){
    for(int i=1;i<=n;i++)d[i]=0;
    for(int i=0;i<31;i++){
        if(mid&(1LL<<i)){
            for(int j=1;j<=n;j++){
                if(d[j])continue;
                if(!(a[j]&(1LL<<i)))d[j]=1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=(d[i]==0);
    return cnt>=m;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(ll i=1LL<<20;i>=0;i--)if(ck(i)){cout<<i;return 0;}
    return 0;
}
