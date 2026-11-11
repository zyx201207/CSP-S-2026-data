#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200500;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    int sum=0,ans=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
        sum+=a;
    }
    for(int i=0;i<(s.size()/2);i++){
        if(s[i]!=s[sum-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
