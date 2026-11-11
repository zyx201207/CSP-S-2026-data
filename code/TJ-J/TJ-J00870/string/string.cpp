#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,ans,j;
char c;
string s,s2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    cin>>a>>c;
    for(int i=2;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    ll t=s.size();
    if(t%2==1){
            t=t/2;
        for(int i=t-1;i>=0;i--){
            s2+=s[i];
        }
        for(int i=t+1;i<s.size();i++){
            if(s2[j]!=s[i])ans++;
            j++;
        }
        cout<<ans<<endl;
    }
    else{
        t=t/2;
        for(int i=t;i>=0;i--){
            s2+=s[i];
        }
        for(int i=t;i<s.size();i++){
            if(s2[j]!=s[i])ans++;
                j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
