#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
string s="";
int n,l;
int ans,ans1,ans2;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int  i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
            s+=c;
        l+=a;
    }
    string s1=s,s2=s;
    for(int i=0;i<l;i++){
        if(s1[i]!=s1[l-1-i]){
            ans1++;
            s1[i]=s1[l-1-i];
        }
    }
    for(int i=l-1;i>=0;i--){
        if(s2[i]!=s2[l-1-i]){
            ans2++;
            s2[i]=s2[l-1-i];
        }
    }
    ans=min(ans1,ans2);
    cout<<ans;
    return 0;
}
