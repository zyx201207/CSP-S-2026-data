#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
ll ans,k,w;
string s;
struct aaa{
    ll a;
    char c;
}g[200100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>g[i].a>>g[i].c;
        if(g[i].c>500){
            cout<<0;
            return 0;
        }
        for(int j=0;j<g[i].a;j++){
            s=s+g[i].c;
        }
        k+=g[i].a;
    }
    k=k/2;
    long long i=0;
    while(i<k){
        if(s[i]!=s[n-i]){
            ans++;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
