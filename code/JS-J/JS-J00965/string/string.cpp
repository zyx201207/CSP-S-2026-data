#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    string s="",s1="";
    char a;
    int p;
    for(int i=1;i<=n;i++){
        cin>>p>>a;
        for(int i=1;i<=p;i++){
            s+=a;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        s1+=s[i];
    }
    int r=s.size();
    //cout<<s1<<endl<<s<<endl;
    for(int i=0;i<s.size();i++){
        if(s1[i]!=s[i]){
            s1[i]=s[i];
            s[r-i-1]=s[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
