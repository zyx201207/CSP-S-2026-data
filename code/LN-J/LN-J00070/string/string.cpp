#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    /*if(n<=10){
        string s="";
        for(int i=1;i<=n;i++){
            ll x;char c;
            cin>>x>>c;
            for(int i=1;i<=x;i++)s+=c;
        }
        ll len=s.size();
        string s1=s.substr(0,len/2);
        string s2=s.substr(len/2+len%2);
        reverse(s2.begin(),s2.end());
        ll ans=0;
        for(int i=0;i<s1.size();i++)ans+=(s1[i]!=s2[i]);
        cout<<ans;
        return 0;
    }
    */
    vector<pair<ll,char>>s(n);
    ll len=0;
    for(int i=0;i<n;i++){
        ll x;char c;
        cin>>x>>c;
        s[i]=(make_pair(x,c));
        len+=x;
    }
    vector<pair<ll,char>>a,b;
    ll la=len/2,lb=len/2;
    for(int i=0;i<n;i++){
        if(la>=s[i].first){
            la-=s[i].first;
            a.push_back(s[i]);
        }
        else{
            a.push_back(make_pair(la,s[i].second));
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(lb>=s[i].first){
            lb-=s[i].first;
            b.push_back(s[i]);
        }
        else{
            b.push_back(make_pair(lb,s[i].second));
            break;
        }
    }
    ll ans=0;
    while(1){
        ll fa=0,fb=0;
        while(a[fa].first==0&&fa<a.size())fa++;
        while(b[fb].first==0&&fb<b.size())fb++;
        //cout<<a[fa].first<<a[fa].second<<b[fb].first<<b[fb].second<<fa<<fb<<" ";
        if(fa>=a.size()){
            cout<<ans;
            break;
        }
        if(a[fa].first<=b[fb].first){
            ans+=a[fa].first*(a[fa].second!=b[fb].second);
            b[fb].first-=a[fa].first;
            a[fa].first=0;
        }
        else{
            ans+=b[fb].first*(a[fa].second!=b[fb].second);
            a[fa].first-=b[fb].first;
            b[fb].first=0;
        }
    }
    return 0;
}

