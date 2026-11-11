#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ng,z=0;
    string zm;
    string s="";
    cin>>n;
    for(int i=0;i<n;i++){
            cin>>ng;
            cin>>zm;
        for(int j=0;j<ng;j++){
           s+=zm;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            z++;
        }
    }
    cout<<z;
    return 0;
}
