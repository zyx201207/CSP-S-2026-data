#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        string a;
        cin>>x>>a;
        for(int j=1;j<=x;j++){
            s=s+a;
        }
    }
    int len=s.size();
    int L=0,R=len-1;
    int ans=0;
    while(L<R){
        if(s[L]!=s[R]){
            ans++;
        }
        L++;
        R--;
    }
    cout<<ans;
    return 0;
}
