#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long a[maxn],s[maxn];
long long n,m;
bool check(long long id,long long Left){
    if(a[id]*(id-Left+1)<=(s[id]-s[Left-1])+m)return true;
    else return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    long long ans=1;
    for(long long i=1;i<=n;i++){
        long long Left=i,Right=n;
        while(Left<=Right){
            long long mid=(Left+Right)/2;
            if(check(mid,i))ans=max(ans,mid-i+1),Left=mid+1;
            else Right=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
//guess:orange green blue purple
