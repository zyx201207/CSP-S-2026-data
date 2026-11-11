#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[200005];
int c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        char x;
        cin>>a[i]>>x;
        c[i]=x-'a';
    }
    if(n==1) cout<<0;
    else if(n==2){
        if(c[1]==c[2]) cout<<0;
        else{
            cout<<min(a[1],a[2]);
        }
    }
    else{
        for(int i=1;i<=n/2;++i){
            if(c[i]!=c[n-i+1]) ans++;
        }
        cout<<ans;
    }
    return 0;
}
