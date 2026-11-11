#include<bits/stdc++.h>
using namespace std;
int ishw(string s){
    int cnt=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt+=1;
        }
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        int tmp=0;
        char a;
        cin>>tmp>>a;
        for(int j=0;j<tmp;j++){
            s+=a;
        }
    }
    cout<<ishw(s);
    return 0;
}
