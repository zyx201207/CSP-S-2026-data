#include <bits/stdc++.h>
using namespace std;
int n,cnt[2005],sz,ans;
char ch[2005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cnt[i]>>ch[i];
        for(int j=1;j<=cnt[i];j++){
            s+=ch[i];
        }
        sz+=cnt[i];
    }
    int cur=0;
    bool flag;
    if(sz%2==0) flag=1;
    else flag=0;
    for(int i=1;i<=sz;i++){
        if((cur==sz-i&&!flag)||(cur+1==sz-i&&flag)) break;
        if(s[cur]==s[sz-i]) continue;
        else{
            ans++;
        }
        cur++;
    }
    cout<<ans;
    return 0;
}
