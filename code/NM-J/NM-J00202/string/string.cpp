#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200010];
    char c[200010];
    string s="";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int len=s.size(),cnt=0;
    string s1,s2,s3="";
    if(len%2==0){
        s1=s.substr(0,len/2);
        s2=s.substr(len/2);
    }
    else{
        s1=s.substr(0,len/2);
        s2=s.substr(len/2+1);
    }
    for(int i=0;i<s2.size();i++){
        s3+=s2[s2.size()-1-i];
        if(s3[i]!=s1[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
