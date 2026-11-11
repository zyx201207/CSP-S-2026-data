#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int n;
long long m;
long long a[maxn];
long long ans=-1;
long long getcnt(int x){
    long long cnt=0;long long sum=0;
    for(int i=x;i>=1;i--){
        if((sum+(a[x]-a[i]))<=m){
            cnt++;
            sum+=(a[x]-a[i]);
        }
        else break;
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            if(getcnt(i)>=ans) ans=getcnt(i);
        }
        cout<<ans<<'\n';
        return 0;
    }
    else{
        long long anss=getcnt(n);
        cout<<anss<<'\n';
        return 0;
    }
    return 0;
}
