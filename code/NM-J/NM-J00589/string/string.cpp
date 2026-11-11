#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans;
char b;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        n+=a;
        for(int j=1;j<=a;j++){
            s=s+b;
        }
    }
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
