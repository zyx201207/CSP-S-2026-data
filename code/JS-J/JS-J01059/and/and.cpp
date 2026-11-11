#include<bits/stdc++.h>
using namespace std;
const int N=2*100000 +5;
long long m=0,n=0,ans=0;
long long num[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    sort(num,num+n);
    ans=num[n];
    for(int i=n;i>n-m;i--)ans=(ans & num[i]);
    cout<<ans<<endl;
    return 0;
    
}
