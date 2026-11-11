#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void p(int a,char c){
    for(int i=1;i<=a;i++){
        s+=c;
    }
    return ;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        ll a;
        char c;
        cin>>a>>c;
        p(a,c);
    }
    ll l=s.size();
    string s1=s,s2=s;
    for(int i=0;i<=l-1;i++){
        s1[i]=s1[l-i-1];
        s2[l-i-1]=s2[i];
    }
    ll cnt1=0,cnt2=0;
    for(int i=0;i<=l-1;i++){
        if(s[i]!=s1[i]){
            cnt1++;
        }
        if(s[i]!=s2[i]){
            cnt2++;
        }
    }
    cout<<min(cnt1,cnt2);
    return 0;
}
