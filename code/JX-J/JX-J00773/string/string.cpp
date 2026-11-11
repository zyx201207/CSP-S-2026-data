#include<bits/stdc++.h>
using namespace std;
long long ans;
long long n;
int a[200005];
char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    for(int i=1;i<=ceil(n/2);i++){
        if(s[i]!=s[n-i+1]){
            if(a[i]==a[n-i+1]) ans=ans+min(a[i],a[n-i+1]);
            if(a[i]!=a[n-i+1]){
                ans=ans+min(a[i],a[n-i+1])+max(a[i],a[n-i+1])-min(a[i],a[n-i+1]);
            }
        }
    }

    cout<<ans;
    return 0;
}
