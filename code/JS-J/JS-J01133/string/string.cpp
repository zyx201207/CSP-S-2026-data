#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++){
            s+=c;
        }
    }
    int cnt=0,len=s.length();
    for(long long i=0;i<len/2;i++){
        if(s[i]!=s[len-1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
