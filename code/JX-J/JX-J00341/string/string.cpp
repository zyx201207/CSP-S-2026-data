#include<bits/stdc++.h>
using namespace std;
int n,ans=0,si=0;
int a[200005];
char c[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    s+=' ';
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
        si+=a[i];
    }
    for(int i=1;i<=(si/2);i++){
        if(s[i]!=s[si+1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
