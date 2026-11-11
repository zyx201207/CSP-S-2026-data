#include<bits/stdc++.h>
using namespace std;
long long j=0,a[101010],ma=INT_MIN;
string s,c,s1,c1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        ma=max(a[i],a[i+1]);
    }
    if(a[1]==ma) cout<<n<<a[n]<<m;
    else if(a[n]==ma) cout<<m<<a[1]<<n;
    else cout<<m<<ma<<n;
   return 0;
}
