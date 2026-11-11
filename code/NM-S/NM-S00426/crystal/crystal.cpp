#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,l=1,ans=1,cnt=1;
long long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        unsigned long long v=(a[i]-a[i-1])*(i-l);
        while(v>m&&l<i){
            m+=(a[i]-a[l]);
            l++;
            cnt--;
        }
        if(v<=m){
            m-=v;
            cnt++;
            ans=max(ans,cnt);
        }
        else break;
    }
    cout<<ans;
    return 0;
}
