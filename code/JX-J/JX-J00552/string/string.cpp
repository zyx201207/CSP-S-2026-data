#include <bits/stdc++.h>
using namespace std;
long long a[200002];
char c[200002];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;//fanzhuanhou
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s.insert(0,a[i],c[i]);
    }
    string sfz=s;
    long long ans=0;
    reverse(s.begin(),s.end());
    if(s==sfz){
        cout<<ans;
    }else{
        string s1,s2;
        if(s.size()%2==1){
        s1=s.substr(0,s.size()/2);
        s2=s.substr(s.size()/2+1,s.size()/2);
        }else{
        s1=s.substr(0,s.size()/2);
        s2=s.substr(s.size()/2,s.size()/2);
        }
        reverse(s2.begin(),s2.end());
        for(long long i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) ans++;
        }
        cout<<ans;
    }
    return 0;
}
