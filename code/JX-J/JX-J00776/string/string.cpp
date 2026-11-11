#include<bits/stdc++.h>
using namespace std;

int hw(string s){
    int i=0;
    int sizee=s.size();
    while(sizee--){
        if(s[i]!=s[s.size()-i-1])return 0;
    }
    return 1;
}
string s;
long long n,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        char a;
        cin>>a;
        for(int j=0;j<x;j++){
            s.push_back(a);
        }
    }
    if(hw(s)==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])cnt++;
    }
    cout<<cnt<<' ';
    //cout<<s;
    return 0;
}
