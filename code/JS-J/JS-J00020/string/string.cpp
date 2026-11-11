#include<bits/stdc++.h>
using namespace std;
const int maxq=2e5+10;
#define ll long long
ll v[maxq],w[maxq],p[maxq];
ll n,cnt,ans;
string s;
char c[maxq];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>p[i]>>c[i];
        cnt+=p[i];
    }
    int flag=0;
    for(int i=2;i<=n;i++){
        if(c[i-1]!=c[i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"0";
        return 0;
    }
    for(ll i=1;i<=n;i++){
        for(int j=1;i<=p[i];i++)s+=c[i];
    }
    s=" "+s;
    if(cnt%2==0){
        for(ll i=1;i<=(cnt/2);i++){
            if(s[i]!=s[cnt-i+1])ans++;
        }
    }
    else{
        for(ll i=1;i<=((cnt-1)/2);i++){
             if(s[i]!=s[cnt-i+1])ans++;
        }
    }
    cout<<ans;
    return 0;
}
