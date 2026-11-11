#include<bits/stdc++.h>
using namespace std;
long long n,ans,i1,a,c;
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
char b1;
cin>>c>>b1;
if(n==1){
    cout<<0;
    return 0;
}
for(long long j=1;j<=c;j++){
    s+=b1;
}
for(int i=2;i<=n;i++){
        char b;
cin>>c>>b;
for(long long j=1;j<=c;j++){
    s+=b;
}
}
a=s.size()-1;
while(i1<a){
    if(s[i1]!=s[a]){
        ans++;
    }
    a--;
    i1++;
}
cout<<ans;
return 0;
}
