#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m;
int ans;
int query(int x){
    int num=0;
    long long sum=0;
    for(int i=x;i>=1;i--){
        if(sum+a[x]-a[i]<=m){
            sum+=a[x]-a[i];
            num++;
        }
        else{
            break;
        }
    }
    return num;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ans=max(ans,query(i));
    }
    cout<<ans;
    return 0;
}
