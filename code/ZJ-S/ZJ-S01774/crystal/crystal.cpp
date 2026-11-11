#include<bits/stdc++.h>
using namespace std;
#define minq priority_queue<ll,vector<ll>,greater<ll> >
#define ll long long
const int maxn=5e5+10;
int n;
ll m,a[maxn];
bool check(int mid){
    ll sum=0;
    minq q;
    for(int i=mid;i>=1;i--){
        if(sum+(a[mid]-a[i])<=m){
            q.push(a[i]);
            sum+=(a[mid]-a[i]);
        }
        else break;
    }
    if(q.size()>=mid) return true;
    for(int i=mid+1;i<=n;i++){
        sum+=q.size()*(a[i]-a[i-1]);
        q.push(a[i]);
        while(!q.empty()&&sum>m){
            sum-=a[i]-q.top();
            q.pop();
        }
        if(q.size()>=mid) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1,r=n,res=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    printf("%d\n",res);
    return 0;
}