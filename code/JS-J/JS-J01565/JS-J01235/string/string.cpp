#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string str="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            str+=c;
        }
    }
    string s=str;
    reverse(s.begin(),s.end());
    if(s==str){
        cout<<0;
        return 0;
    }
    long long len=str.size();
    int ans=0;
    string str1=str.substr(0,ceil(len*1.0/2));
    string str2=str.substr(ceil(len*1.0/2)+1,len-1);
    int lm;
    lm=len/2;
    for(int i=0;i<lm;i++){
        if(str1[i]!=str2[i]) ans++;
    }
    cout<<ans;
    return 0;
}
