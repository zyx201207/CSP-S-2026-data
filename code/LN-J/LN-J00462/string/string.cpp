#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
string b[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0,ans=0;
    string s=" ";
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    for(int i=1;i<=sum/2;i++){
        if(s[i]!=s[sum-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
