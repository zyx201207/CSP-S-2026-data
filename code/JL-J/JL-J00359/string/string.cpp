#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s+=b;
        }
    }
    char tmp[s.size()];
    for(int i=0;i<s.size();i++){
        tmp[s.size()-i-1]=s[i];
    }
    int cnt=0;
    bool errcc=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=tmp[i]){
            cnt++;
            errcc=true;
        }
    }
    if(errcc){
        cout<<cnt/2;
    }else{
        printf("0");
    }
    return 0;
}
