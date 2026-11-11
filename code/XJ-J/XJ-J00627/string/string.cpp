#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        int len;
        char word;
        cin>>len>>word;
        string ss(len,word);
        s+=ss;
    }
    bool ok=0;
    for(int i=0;i<s.length();i++){
        int j=s.length()-1-i;
        if(s[i]!=s[j]){
            ok=1;
        }
    }
    if(ok==0){
        cout<<0;
    }
    else{
        int sum=0;
        for(int i=0;i<s.length();i++){
            int j=s.length()-1-i;
            if(i>=j){
                break;
            }
            if(s[i]!=s[j]){
                sum++;
            }
        }
        cout<<sum;
    }
    return 0;
}
