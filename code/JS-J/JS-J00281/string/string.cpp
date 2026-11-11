#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n;
int a;
char c;
ll sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        sum+=a;
        while(a--) s+=c;
    }
    int t=sum;
    sum=sum/2+1;
    ll l=sum-1,r=sum+1,ans=sum-1;
    if(t%2==0) r--;
    for(;l>1;l--,r--){
        if(s[l]==s[r]) ans-=2;
    }
    cout<<ans;
    return 0;
}
