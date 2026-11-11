#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n,ans=0;
    cin>>n;
    while(n--){
        int k;
        string a;
        cin>>k>>a;
        while(k--)s=s+a;
    }
    for(int i=0;i*2<s.size();i++){
        if(s[i]!=s[s.size()-i-1])ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
