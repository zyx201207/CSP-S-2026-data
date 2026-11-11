#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,ans=0,s=0;
    string m;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        char y;
        cin>>x>>y;
        s+=x;
        for(int j=0;j<x;j++){
            m+=y;
        }
    }
    for(int i=0;i<s/2;i++){
        if(m[i]!=m[s-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
