#include <bits/stdc++.h>
using namespace std;
string s;
long long n,m,cnt;
bool f;
char c,d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>c;
        if(i==1) d=c;
        if(c!=d) f=true;
        for(int j=1;j<=m;j++){
            s+=c;
        }
    }
    if(!f){
        cout<<0;
        return 0;
    }
    for(int i=0;i<=s.size()/2-1;i++){
        if(s[i]!=s[s.size()-1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
