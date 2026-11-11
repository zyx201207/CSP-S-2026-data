#include<bits/stdc++.h>
using namespace std;
string s;
long long n,ans=0,l=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(long long i=0;i<n;i++){
    long long a;
    char c;
    cin>>a>>c;
    for(long long k=l;k<a+l;k++){
        s[k]=c;}
    l+=a;
}

for(long long i=0;i<l;i++){
    if(s[i]!=s[n+1-i]) {
        ans+=1;
        s[i]=s[n+1-i];
    }
}
cout<<ans;
fclose(stdin);
fclose(stdout);
return 0;
}
