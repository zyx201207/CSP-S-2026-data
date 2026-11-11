#include<bits/stdc++.h>
using namespace std;
bool hw(string s){
    string temp;
    for(int i=s.size()-1;i>=0;i--){
        temp+=s[i];
    }if(temp==s)return true;
    return false;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }if(hw(s)){
        cout<<0;
    }
    return 0;
}

