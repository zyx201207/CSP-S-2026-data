#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    int a[n];
    char c[n];
    string s="";
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    n=s.length();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
