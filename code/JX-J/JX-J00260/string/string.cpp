#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int cnt;
string s;
string s2;
int len;
bool check(string s1){
    len=s1.size();
    for(int j=len-1;j>=0;j--){
        s2+=s1[j];
    }

    if(s2==s1) return 1;
    else return 0;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    if(check(s)){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]!=s2[i]){
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
