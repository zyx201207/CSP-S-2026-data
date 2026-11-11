#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans=INT_MAX;
char c[200005];
void dfs(int dep,string s,int xb){
    if(dep=n){
        for(int i=xb;i<=n;i++){
            string s1;
            for(int j=1;j<=i;j++){
                s1+=c[i];
            }
            s1+=s;
            int cnt;
            for(int i=0;i<s.size()/2;i++){
                if(s[i]!=s[s.size()-i+1]) cnt++;
            }
            ans=min(cnt,ans);
        }
    }
    for(int i=xb;i<=n;i++){
        string s1;
        for(int j=1;j<=i;j++){
            s1+=c[i];
        }
        dfs(dep+1,s+s1,i);
    }
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int j=1;j<=n;j++) cin>>a[j],cin>>c[j];
    dfs(1,"",1);
    cout<<ans;
    return 0;
}
