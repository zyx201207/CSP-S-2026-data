#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
long long now;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    now=a[1];
    long long res=1,ans=1;
    long long q=m;
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        q-=ans*(a[i]-now);
        while(q<0){
            ans--;q+=now-a[i-ans];
        }
        ans++;
        res=max(ans,res);now=a[i];
    }
    cout<<res;
    return 0;
}
