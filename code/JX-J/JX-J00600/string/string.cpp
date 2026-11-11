#include<bits/stdc++.h>
using namespace std;
string s;
bool is_hw(string s){
    if(s.size()==1) return 1;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i]) return 0;
    }return 1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int x;
    char c;
    cin>>n;
    while(n--){
        cin>>x>>c;
        for(int i=1;i<=x;i++) s+=c;
    }if(is_hw(s)){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]) cnt++;;
    }cout<<cnt;
    return 0;
}
