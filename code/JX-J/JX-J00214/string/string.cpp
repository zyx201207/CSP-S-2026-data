#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
    int a;
    string b;
    cin>>a>>b;
    for(int j=1;j<=a;j++){
        s+=b;
    }
}
string s1;
for(int i=s.size();i>0;i--){
    s1+=s[i];
}
int sum=0;
for(int i=1;i<=s.size();i++){
    if(s1[i]!=s[i]){
        sum++;
    }
}
cout<<sum;
return 0;
}



