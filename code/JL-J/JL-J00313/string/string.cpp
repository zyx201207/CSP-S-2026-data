#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin >> a;
    string s="";
    for(int i=1;i<=a;i++){
        int k;
        string j;
        cin >> k >> j;
        for(int l=1;l<=k;l++){
            s+=j;
        }
    }
    unsigned long long cnt=0,cd=s.size()-1;
    string jl="";
    while(cd>=0){
        jl+=s[cd];
        cd--;
    }
    if(jl==s){
        cout << cnt;
    }
    else{
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=jl[i]){
                cnt++;
            }
        }
        cout << cnt;
    }
    return 0;
}
