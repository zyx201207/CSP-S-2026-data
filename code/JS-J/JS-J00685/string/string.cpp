#include<bits/stdc++.h>
using namespace std;
#define int long long
int change(string s){
    string s1="";
    int ans=0;
    for(int i=s.size()-1;i>=0;i--) {s1+=s[i];}
    for(int i=0;i<=s.size()/2;i++) if(s[i]!=s1[i])ans++;
    return ans;
}
//hyw
string s;
int n,a;
char c;
signed main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++) s=s+c;
    }
    cout<<change(s);
    return 0;


}
