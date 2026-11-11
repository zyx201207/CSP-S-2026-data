#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
string t;
char c;
int n,x[200005],cnt;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool isA=true;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>c;
        if(i>1&&x[i]!=x[i-1])isA=false;
        t+=c;
        for(int j=0;j<x[i];j++)s+=c;
    }
    if(isA){
        int cnt1=0;
        for(int i=0;i<(t.size()%2==0?t.size()/2:t.size()/2+1);i++){
            if(t[i]!=t[t.size()-i-1])cnt1++;
        }
        cout<<cnt1*x[1];
        return 0;
    }
    for(int i=0;i<(s.size()%2==0?s.size()/2:s.size()/2+1);i++){
        if(s[i]!=s[s.size()-i-1])cnt++;
    }
    cout<<cnt;
    return 0;
}
