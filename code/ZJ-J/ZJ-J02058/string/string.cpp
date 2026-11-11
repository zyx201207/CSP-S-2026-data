#include <bits/stdc++.h>
using namespace std;
long long n,temp=0,cnt=0;
long long a[100000001];
string c;
char b[1000000009];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(long long i=0;i<n;i++){
    cin>>a[i]>>c[i];
    for(long long j=0;j<a[i];j++) b[j+temp]=c[i];
    temp+=a[i];
}
for(long long i=0;i<temp/2;i++){
    if(b[i]!=b[temp-i-1]) cnt++;
}
cout<<cnt;
fclose(stdin);
fclose(stdout);
return 0;
}
