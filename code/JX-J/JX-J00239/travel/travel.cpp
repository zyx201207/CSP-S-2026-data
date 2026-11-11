#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        char e;
        cin>>m;
        cin>>e;
        string z="";
        for(int j=0;j<m;j++)z+=e;
        s+=z;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
            s[i]=s[s.size()-i-1];
        }
    }cout<<ans;
    return 0;
}
