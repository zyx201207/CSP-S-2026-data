#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
string s;
cin>>n;
long long w=0;
long long a;
long long h=0;
char f;
for(int i=0;i<n;i++){
    cin>>a>>f;
    w=w+a;
for(int j=h;j<=a+h;j++){
s[j]=f;
}
h=h+a;
}
bool g=1;
for(int i=0;i<w;i++){
if(s[i]!=s[1]){
   g=0;
}
}
if(g==1){
    cout<<0;
    return 0;
}
long long z;
if(w%2==0){
    z=w/2;
}else{
z=(w-1)/2;
}
for(int i=0;i<z;i++){
if(s[i]==s[w-i]){
   z--;
}
}
cout<<z;
return 0;
}
