#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll len[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i]>>c[i];
    }
    ll i=1,j=n,ans=0;
    while(i<j){
        if(len[i]==len[j]){
            ans+=((c[i]!=c[j])*len[i]);
            i++;j--;
        }
        if(len[i]>len[j]){
            ans+=(c[i]!=c[j])*len[j];
            len[i]-=len[j];
            j--;
        }
        if(len[i]<len[j]){
            ans+=(c[i]!=c[j])*len[i];
            len[j]-=len[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
