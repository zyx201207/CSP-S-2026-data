#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[500050];
bool check(int x){
    int sum=0;
    int num=0;
    for(int i=1;i<x;i++)sum+=a[i];
    for(int i=x;i<=n;i++){
        sum+=a[i];
        sum-=a[i-x];
        if(sum+m>=x*a[i])return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int L=1,R=n;
    int time=0;
    while(L<=R){
        if(L==R)break;
        int mid=(L+R+1)>>1;
        if(check(mid))L=mid;
        else R=mid-1;
        time++;
        if(time>n)break;
    }
    cout<<L;
    return 0;
}
