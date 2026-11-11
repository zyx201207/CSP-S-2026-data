#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500020];
long long ans,mx,x,num,whei;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    //priority_queue<long long,vector<long long>,greater<long long>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[0]=a[1];
    for(int i=1;i<=n;i++){
        x=x+(a[i]-a[i-1])*num;
        num++;
        while(x>m){
            x=x-a[i]+a[++whei];
            num--;
        }
        ans=max(ans,num);
    }
    cout<<ans;
    return 0;
}
