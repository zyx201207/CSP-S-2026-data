#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=0;i<n;i++){
        int a;
        char ch;
        cin>>a>>ch;
        for(int j=0;j<a;j++){
            s+=ch;
        }
    }
    string ss="";
    for(int i=s.size()-1;i>=0;i--){
        ss+=s[i];
    }
    int sum=0;
    for(int i=0;i<s.size();i++){
        if(ss[i]!=s[i]) sum++;
    }
    cout<<sum/2<<'\n';

    return 0;
}
