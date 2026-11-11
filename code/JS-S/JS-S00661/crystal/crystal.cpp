#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],su[500005],ans,k,sum,sta=1,qwq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        su[i-1]=a[i]-a[i-1];
        k+=su[i-1];
        sum+=su[i-1]*(i-sta);
        qwq++;
        while(sum>m&&sta<i){
            sum-=k;
            k-=su[sta++];
            ans=max(ans,qwq);
            qwq--;
        }
    }
    cout<<ans;
    return 0;
}
