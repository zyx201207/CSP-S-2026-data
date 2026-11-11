#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define F1 freopen("string.in","r",stdin)
#define F2 freopen("string.out","w",stdout)
void io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
ll n,ans,l,r,L;
pair<ll,char>s[200000+100];
int main(){
    F1;F2;
    io();
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a;
        string c;
        cin>>a>>c;
        s[i]={a,c[0]};
    }
    l=1;r=n;
    while(l<r){
        while(s[l].first==0)l++;
        while(s[r].first==0)r--;
        if(s[l].second!=s[r].second){
            if(s[l].first<s[r].first){
                ans+=s[l].first;
                s[r].first-=s[l].first;
                s[l].first=0;
                l++;
            }
            else if(s[l].first>s[r].first){
                ans+=s[r].first;
                s[l].first-=s[r].first;
                s[r].first=0;
                r--;
            }
            else if(s[l].first==s[r].first){
                ans+=s[l].first;
                s[l].first=0;
                s[r].first=0;
                l++;r--;
            }
        }
        else{
            if(s[l].first<s[r].first){
                s[r].first-=s[l].first;
                s[l].first=0;
                l++;
            }
            else if(s[l].first>s[r].first){
                s[l].first-=s[r].first;
                s[r].first=0;
                r--;
            }
            else if(s[l].first==s[r].first){
                s[l].first=0;
                s[r].first=0;
                l++;r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
