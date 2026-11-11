#include<bits/stdc++.h>
using namespace std;
int n,t,cnt=0;
string s,k;
int main()
{
    freopen("string3.in","r",stdin);
    freopen("string3.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t>>k;
        for(int j=1;j<=t;j++) s+=k;
    }
    int l=s.size();
    for(int i=l/2;i<l;i++){
        if(s[i]!=s[l+1-i]) cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}
