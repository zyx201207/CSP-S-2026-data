#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],l=1,num,maxn;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        num+=a[i];
        while(a[i]*(i-l+1)-num>m)num-=a[l],l++;
        maxn=max(maxn,i-l+1);
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
