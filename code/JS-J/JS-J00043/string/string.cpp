#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long cnt=0;
bool flag=true;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    int m;
    cin>>m;
    char c;
    cin>>c;
    for(int i=1;i<=m;i++){
        s+=c;
    }
}
for(int i=0,x=s.size();i<=s.size()/2;i++,x--){
   if(s[i]!=s[x]){
    cnt++;
    flag=false;
   }
}if(flag=true){
    cout<<0;
}else cout<<cnt;
return 0;
}
