#include<bits/stdc++.h>
using namespace std;
long long s[10000000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    long long ya=0;
    for(int i=1;i<=n;i++){
        long long ans=s[i];
        for(int j=i+1;j<n;j++){
            ans=(ans&s[j]);
        }
        if(ya<ans) ya=ans;
    }
    cout<<ya;
    return 0;
}
