#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++) s+=c[i];
    }
    int m=s.size();
    int ans=0;
    if(m%2==1){
        for(int i=0;i<(m-1)/2;i++){
            if(s[i]!=s[m-1-i]) ans++;
        }
    }

    else{
        for(int i=0;i<m/2;i++){
            if(s[i]!=s[m-1-i]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
