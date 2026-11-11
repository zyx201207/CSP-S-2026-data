#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,ans=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c,c1;
        int shu;
        cin>>shu>>c;
        for(int j=1;j<=shu;j++){
            s+=c;
        }
    }
    long long x=s.size();
    for(int i=0;i<x;i++){
        int xi=x-1-i;
        if(s[i]!=s[xi]){
            s[xi]=s[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
