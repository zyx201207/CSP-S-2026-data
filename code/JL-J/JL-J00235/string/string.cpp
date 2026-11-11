#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    long long a;
    cin>>a;
    int len=0;
    for(int i=1;i<=a;i++){
        long long b;
        cin>>b;
        string c;
        cin>>c;
        for(int j=0;j<b;j++){
            s[len++]=c[0];
        }
    }
    int all=0;
    for(int i=0;i<len;i++){
        if(s[i]!=s[len-i]){
            all++;
            s[len-1]==s[i];
        }
    }
    cout<<all-1;
    return 0;
}
