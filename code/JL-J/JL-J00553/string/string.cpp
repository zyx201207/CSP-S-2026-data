#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string s;
ll sum=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    s+=" ";
    for(int i=1;i<=n;i++){
        int a;
        char s1;
        cin>>a>>s1;
        sum+=a;
        for(int i=1;i<=a;i++){
            s+=s1;
        }
    }
    ll cnt=0;
    if(sum%2==0){
        for(int i=1;i<=sum/2;i++){
            if(s[i]!=s[sum+1-i]) cnt++;
        }
    }
    else{
        for(int i=1;i<=(sum-1)/2;i++){
            if(s[i]!=s[sum+1-i]) cnt++;
        }
    }
    cout<<cnt;

    //cout<<s;

    return 0;
}
