#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];char s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //freopen("string.out","r",stdout);
    //freopen("string.in","w",stdin);
    //wo xiang shang mi huo xing wei da shang
    ll n;
    cin>>n;
    ll sum=0,ans=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    ll p=1,q=n;
    while(p<q){
        if(a[p]<a[q]){
            if(s[p]!=s[q]){
                ans+=a[p];
            }
            a[q]-=a[p];
            p++;
        }
        else{
            if(s[p]!=s[q]){
                ans+=a[q];
            }
            a[p]-=a[q];
            q--;
        }
    }
    cout<<ans;
    return 0;
}/*
cong liang bian mei ju zai xiang zhong jian kao long dao zhong jian shi,
zi fu dou yi yang,suo yi wu xu tong ji da an
*/
