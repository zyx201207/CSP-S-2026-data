#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string p,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x>>p;
        for(int j=0;j<x;j++){
            s+=p;
        }
    }
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
