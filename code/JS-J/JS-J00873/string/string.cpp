#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char b[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
     cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s=s+b[i];
        }
    }
    long long len=s.length();
    for(int i=1;i<=len/2;i++){
       if(s[i-1]!=s[len-i]){
        ans++;
       }
    }
    cout<<ans;
    return 0;
}
