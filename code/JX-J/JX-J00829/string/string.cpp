#include<iostream>
#include<cstdio>
using namespace std;
#define int unsigned long long
int n,x,ans,s[200010];
char c[200010],p;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    cin>>x>>p;
    s[i]=x;
    c[i]=p;
}
for(int i=0,j=n-1;i<n&&j>=0;){
    if(i>=j)break;
if(s[i]==s[j]){
ans+=(c[i]==c[j]?0:s[i]);
i++;j--;
}
else if(s[i]>s[j]){
ans+=(c[i]==c[j]?0:s[j]);
s[i]-=s[j];
j--;
}
else{
ans+=(c[i]==c[j]?0:s[i]);
s[j]-=s[i];
i++;
}
}
cout<<ans;
    return 0;
}