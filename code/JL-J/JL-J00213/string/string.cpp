#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    long long t=0;
    for(int i=1;i<=n;i++){
        int tt;
        char c;
        cin>>tt>>c;
        t+=tt;
        for(int j=1;j<=tt;j++){
            s+=c;
        }
    }

    int ans=0;
    if(t%2==1){
        for(int i=0,j=s.size()-1;i<=t/2-1,j>=t/2+1;i++,j--){
            if(s[i]!=s[j]) ans++;
        }
    }else{
        for(int i=0,j=s.size()-1;i<=t/2-1,j>=t/2;i++,j--){
            if(s[i]!=s[j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
