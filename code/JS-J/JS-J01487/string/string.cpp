#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,sum;
string s=" ";
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;char c;
        cin>>x>>c;
        sum+=x;
        while(x--)s+=c;
    }
    for(int i=1;i<=sum/2;i++)
        if(s[i]!=s[sum+1-i])ans++;
    cout<<ans;
    return 0;
}
