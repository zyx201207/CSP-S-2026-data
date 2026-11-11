#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,length,a[200010],b[200010],ans;
char c[200010];
char s[100010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        length+=a[i];
        b[i]=length;
        for(ll j=b[i-1]+1;j<=b[i];j++){
            s[j]=c[i];
        }
    }
    for(ll i=1;i<=length/2;i++){
        if(s[i]!=s[length+1-i])ans++;
    }
    cout<<ans;
    return 0;
}
