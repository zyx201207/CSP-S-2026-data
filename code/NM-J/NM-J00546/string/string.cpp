#include<bits/stdc++.h>
using namespace std;
int n,t,w,ans;
string s,s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    char c;
    for(int i=0;i<n;i++){
        cin>>t;
        cin>>c;
        for(int j=0;j<t;j++){
            s+=c;
        }
    }
    w=s.size()/2;
    s1=s;
    s2=s;

    for(int i=0;i<w;i++){
        s1[i]=s[i];

    }
    t=0;
    for(int j=s.size()-1;j>s.size()-w-1;j--){
            s2[t]=s[j];
            t++;
        }
    for(int i=0;i<w;i++){
        if(s1[i]!=s2[i]){
            ans++;
        }
    }
    cout<<ans;
return 0;
}
